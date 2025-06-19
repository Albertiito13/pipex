/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:12:54 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/19 19:24:16 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

# include "libft/libft.h"

char	*get_cmd_path(char *cmd, char **envp);
void	free_array(char **arr);
void	exit_error(const char *msg, int code, char **cmd, char *path);
void	arg_error(void);

#endif
