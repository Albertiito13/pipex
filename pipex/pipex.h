/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:12:54 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/18 21:11:34 by albcamac         ###   ########.fr       */
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

# include "libft/libft.h"

char	*get_cmd_path(char *cmd, char **envp);
void	free_array(char **arr);
void	exit_error(const char *msg);
void	arg_error(void);

#endif
