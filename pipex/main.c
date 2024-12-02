/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:42:26 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/03 00:17:06 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex/ft_libft/libft.h"
#include "pipex.h"

int	error_message(char *message)
{
	perror(message);
	exit(1);
}

int	open_files(t_cmd *cmd, char **argv)
{
	cmd->fd1 = open(argv[1], O_RDONLY);
	if (cmd->fd1 == -1)
		return (error_message("input file error"));
	cmd->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->fd2 == -1)
		return (error_message("output file error"));
	return (0);
}

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_command(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (NULL);
}

void	child_free(t_cmd *cmd)
{
	free(cmd->cmd);
	free(cmd->args);
	free(cmd->cmd_path);
	free(cmd->paths);
}

void	create_child1(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid1 = fork();
	if (cmd->pid1 == -1)
		error_message("Fork failed");
	if (cmd->pid1 == 0)
		child1(cmd, argv, env);
}

void	create_child2(t_cmd *cmd, char **argv, char **env)
{
	cmd->pid2 = fork();
	if (cmd->pid2 == -1)
		error_message("Fork failed");
	if (cmd->pid2 == 0)
		child2(cmd, argv, env);
}

void	child1(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tube[1], STDOUT_FILENO);
	close(cmd->tube[0]);
	dup2(cmd->fd1, STDIN_FILENO);
	cmd->args = ft_split(argv[2], ' ');
	cmd->cmd = get_command(cmd->cmd_path, cmd->args[0]);
	if (cmd->cmd == NULL)
	{
		child_free(cmd);
		error_message("Error: Command not found");
	}
	execve(cmd->cmd, cmd->args, env);
}
void	child2(t_cmd *cmd, char **argv, char **env)
{
	dup2(cmd->tube[0], STDIN_FILENO);
	close(cmd->tube[1]);
	dup2(cmd->fd2, STDOUT_FILENO);
	cmd->args = ft_split(argv[3], ' ');
	cmd->cmd = get_command(cmd->cmd_path, cmd->args[0]);
	if (cmd->cmd == NULL)
	{
		child_free(cmd);
		error_message("Error: Command not found");
	}
	execve(cmd->cmd, cmd->args, env);
}
void	parent_free(t_cmd *cmd)
{
	close(cmd->fd1);
	close(cmd->fd2);
	free(cmd->cmd_path);
}
void	close_command(t_cmd *cmd)
{
	close(cmd->fd1);
	close(cmd->fd2);
	close(cmd->tube[0]);
	close(cmd->tube[1]);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd cmd;
	int p;
	int o;

	if (argc != 5)
		error_message("Error: Wrong number of arguments");
	o = open_files(&cmd, argv);
	if (o == -1)
		return (1);
	p = pipe(cmd.tube);
	if (p == -1)
		return (error_message("pipe failed"));
	cmd.paths = get_path(env);
	cmd.cmd_path = ft_split(cmd.paths, ':');
	create_child1(&cmd, argv, env);
	create_child2(&cmd, argv, env);
	close_command(&cmd);
	waitpid(cmd.pid1, NULL, 0);
	waitpid(cmd.pid2, NULL, 0);
	parent_free(&cmd);
}