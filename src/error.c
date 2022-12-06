/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:10 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:11 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_pipe(void)
{
	perror("pipe error");
	exit (0);
}

void	error_fork(void)
{
	perror("func fork error");
	exit (0);
}

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit (0);
}

void	error_open(void)
{
	perror("open");
	exit (0);
}

void	error_execve(void)
{
	perror("func execve error");
	exit (0);
}
