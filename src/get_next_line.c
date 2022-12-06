/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:17 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:18 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	run_cmd_bonus(char *argv, char **envp, int fd)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(envp, cmd[0], 0);
	if (!path)
		print_error("cmd not found");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(path, cmd, envp) == -1)
		error_execve();
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		i;
	int		ret;
	char	c;

	i = 0;
	buf = (char *)malloc(10000);
	if (!buf)
		return (-1);
	ret = read(fd, &c, 1);
	while (ret && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buf[i] = c;
		i++;
		ret = read(0, &c, 1);
	}
	buf[i] = '\n';
	buf[++i] = '\0';
	*line = buf;
	free(buf);
	return (ret);
}

int	ft_strlen_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c)
		count++;
	return (count);
}

void	run_cmd_here_doc(char **line, char **envp, int fd)
{
	int		pid;
	int		i;

	i = 0;
	while (line[i])
	{
		pid = fork();
		if (pid == 0)
			run_cmd_bonus(line[i], envp, fd);
		else
			waitpid(pid, NULL, 0);
		i++;
	}
}
