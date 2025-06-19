/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:09:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/19 19:33:29 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_for_children(pid_t pid2)
{
	int		status;
	int		status2;
	int		waited;
	pid_t	pid;

	waited = 0;
	while (waited < 2)
	{
		pid = wait(&status);
		if (pid == pid2)
			status2 = status;
		waited++;
	}
	return ((status2 >> 8) & 0xFF);
}

static void	child1(char **av, int *fd, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		exit_error(NULL, 1, NULL, NULL);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	cmd = ft_split(av[2], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		exit_error("Command not found", 127, cmd, NULL);
	path = get_cmd_path(cmd[0], envp);
	if (!path)
		exit_error("Command not found", 127, cmd, NULL);
	if (access(path, X_OK) != 0)
		exit_error("Permission denied", 126, cmd, path);
	execve(path, cmd, envp);
	free_array(cmd);
	if (path != cmd[0])
		free(path);
	exit(1);
}

static void	child2(char **av, int *fd, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		exit_error(NULL, 1, NULL, NULL);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		exit_error("Command not found", 127, cmd, NULL);
	path = get_cmd_path(cmd[0], envp);
	if (!path)
		exit_error("Command not found", 127, cmd, NULL);
	if (access(path, X_OK) != 0)
		exit_error("Permission denied", 126, cmd, path);
	execve(path, cmd, envp);
	if (path != cmd[0])
		free(path);
	free_array(cmd);
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		exit_error("Numero de argumentos no valido", 1, NULL, NULL);
	if (pipe(fd) == -1)
		exit_error(NULL, 1, NULL, NULL);
	pid1 = fork();
	if (pid1 < 0)
		exit_error(NULL, 1, NULL, NULL);
	if (pid1 == 0)
		child1(av, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit_error(NULL, 1, NULL, NULL);
	if (pid2 == 0)
		child2(av, fd, envp);
	close(fd[0]);
	close(fd[1]);
	return (wait_for_children(pid2));
}
