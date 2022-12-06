/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:04:43 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:04:44 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc_find(char *here, int *fd)
{
	char	*word;
	char	*line;

	word = ft_strjoin(here, "\n");
	close(fd[0]);
	while (get_next_line(0, &line))
	{
		if (ft_strnstr(line, word, ft_strlen(word)))
		{
			free(word);
			close(fd[1]);
			exit (EXIT_SUCCESS);
		}
		write(fd[1], line, ft_strlen(line));
	}
}

void	pipex_for_here_doc(char *word)
{
	int		pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error_pipe();
	pid = fork();
	if (pid == 0)
		here_doc_find(word, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	child_bonus(char *argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error_pipe();
	pid = fork();
	if (pid < 0)
		error_fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		run_cmd(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	run_child(int i, int j, char **argv, char **envp)
{
	while (i < j)
	{
		child_bonus(argv[i], envp);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_infile;
	int	fd_outfile;

	if (argc < 6)
		print_error("not arguments");
	if (ft_strnstr(argv[1], "here_doc", 8))
	{
		fd_outfile = open_file_wronly_append(argv[argc - 1]);
		i = 3;
		pipex_for_here_doc(argv[2]);
	}
	else
	{
		fd_outfile = open_file_wronly_trunc(argv[argc - 1]);
		i = 2;
		fd_infile = open_file_rdonly(argv[1]);
		dup2(fd_infile, STDIN_FILENO);
	}
	run_child(i, argc - 2, argv, envp);
	dup2(fd_outfile, STDOUT_FILENO);
	run_cmd(argv[argc - 2], envp);
}
