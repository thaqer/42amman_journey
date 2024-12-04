/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:46:36 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/04 16:27:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex/ft_libft/libft.h"
#include "pipex.h"

void	error_message(char *message, t_cmd *cmd)
{
	close_command(cmd);
	perror(message);
	exit(1);
}

void	child_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	if (cmd->args)
	{
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	i = 0;
	if (cmd->cmd_path)
	{
		while (cmd->cmd_path[i])
			free(cmd->cmd_path[i++]);
		free(cmd->cmd_path);
	}
	if (cmd->paths)
		free(cmd->paths);
}

void	parent_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd == NULL)
		return ;
	if (cmd->fd1 >= 0)
		close(cmd->fd1);
	if (cmd->fd2 >= 0)
		close(cmd->fd2);
	if (cmd->cmd_path)
	{
		while (cmd->cmd_path[i])
			free(cmd->cmd_path[i++]);
		free(cmd->cmd_path);
	}
}

void close_command(t_cmd *cmd)
{
    if (cmd == NULL)
        return;

    if (cmd->fd1 >= 0) // Only close if fd1 is initialized
    {
        close(cmd->fd1);
        cmd->fd1 = -1; // Mark as closed
    }

    if (cmd->fd2 >= 0) // Only close if fd2 is initialized
    {
        close(cmd->fd2);
        cmd->fd2 = -1; // Mark as closed
    }

    // Any other descriptors should be checked similarly
}

void	error_process(char *massage, t_cmd *cmd)
{
	close_command(cmd);
	error_message(massage, cmd);
}
