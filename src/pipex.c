/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:30 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:31 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_p(char **argv, char **envp, int *fd)
{
	int	fd_infail;

	fd_infail = open(argv[1], O_RDONLY);
	if (fd_infail == -1)
		error_open();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_infail, STDIN_FILENO);
	close(fd[0]);
	run_cmd(argv[2], envp);
}

void	parent_p(char **argv, char **envp, int *fd)
{
	int	fd_outfail;

	fd_outfail = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_outfail == -1)
		error_open();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_outfail, STDOUT_FILENO);
	close(fd[1]);
	run_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error_pipe();
		pid = fork();
		if (pid < 0)
			error_fork();
		if (!pid)
			child_p(argv, envp, fd);
		else
			parent_p(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		print_error("not arguments");
}
