/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:43:02 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/03 00:19:05 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../pipex/ft_libft/libft.h"

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	*paths;
	char	**cmd_path;
	char	**args;
	int		fd1;
	int		fd2;
	int		tube[2];
}			t_cmd;

int			error_message(char *message);
int			massage(char *massage);
int			open_files(t_cmd *cmd, char **argv);
char		*get_path(char **env);
char		*get_command(char **path, char *cmd);
void		child_free(t_cmd *cmd);
void		child1(t_cmd *cmd, char **argv, char **env);
void		child2(t_cmd *cmd, char **argv, char **env);
void		parent_free(t_cmd *pipex);
void		close_command(t_cmd *cmd);

#endif