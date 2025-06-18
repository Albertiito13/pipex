/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:09:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/18 21:35:37 by albcamac         ###   ########.fr       */
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
	return (WEXITSTATUS(status2));
}

static void	exit_cmd_error(char **cmd, const char *msg, int code)
{
	if (msg && cmd && cmd[0])
		fprintf(stderr, "pipex: %s: %s\n", cmd[0], msg);
	else if (msg)
		fprintf(stderr, "pipex: %s\n", msg);
	free_array(cmd);
	exit(code);
}

static void	child1(char **av, int *fd, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		exit_error("pipex: No such file or directory");
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	cmd = ft_split(av[2], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		exit_cmd_error(cmd, "command not found", 127);
	path = get_cmd_path(cmd[0], envp);
	if (!path)
		exit_cmd_error(cmd, cmd[0], 127);
	if (access(path, X_OK) != 0)
		exit_cmd_error(cmd, "Permission denied", 126);
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
		exit_error("pipex: Cannot open output file");
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	cmd = ft_split(av[3], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		exit_cmd_error(cmd, "command not found", 127);
	path = get_cmd_path(cmd[0], envp);
	if (!path)
		exit_cmd_error(cmd, "command not found", 127);
	if (access(path, X_OK) != 0)
		exit_cmd_error(cmd, "Permission denied", 126);
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
		arg_error();
	if (pipe(fd) == -1)
		exit_error("pipex: pipe");
	pid1 = fork();
	if (pid1 < 0)
		exit_error("pipex: fork1");
	if (pid1 == 0)
		child1(av, fd, envp);
	pid2 = fork();
	if (pid2 < 0)
		exit_error("pipex: fork2");
	if (pid2 == 0)
		child2(av, fd, envp);
	close(fd[0]);
	close(fd[1]);
	return (wait_for_children(pid2));
}
