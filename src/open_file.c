/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:21 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:22 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file_rdonly(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		error_open();
	return (fd);
}

int	open_file_wronly_append(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error_open();
	return (fd);
}

int	open_file_wronly_trunc(char *s)
{
	int	fd;

	fd = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_open();
	return (fd);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}
