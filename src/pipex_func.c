/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:25 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:26 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_all(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	**find_in_envp(char **envp)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	tmp = ft_strdup(envp[i] + 5);
	path = ft_split(tmp, ':');
	free(tmp);
	return (path);
}

char	*find_path(char **envp, char *argv, int i)
{
	char	*cmd;
	char	*tmp;
	char	**path;

	cmd = ft_strjoin("/", argv);
	path = find_in_envp(envp);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK))
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			free(cmd);
			free_all(path);
			return (tmp);
		}
		i++;
	}
	free_all(path);
	free(cmd);
	return (NULL);
}

void	run_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(envp, cmd[0], 0);
	if (!path)
		print_error("command not found");
	if (execve(path, cmd, envp) == -1)
		error_execve();
}
