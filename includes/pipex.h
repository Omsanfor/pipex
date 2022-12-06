/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:05 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:06 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdarg.h>

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int s, size_t l);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
void	error_pipe(void);
void	error_fork(void);
void	print_error(char *s);
void	error_open(void);
char	*find_path(char **envp, char *argv, int i);
void	error_execve(void);
int		open_file_rdonly(char *s);
int		open_file_wronly_append(char *s);
int		open_file_wronly_trunc(char *s);
void	run_cmd(char *argv, char **envp);
int		get_next_line(int fd, char **line);
int		ft_strncmp(const char *str, const char *str2, size_t n);
char	*ft_strstr(char *str, char *to_find);
int		ft_strlen_char(const char *str, char c);
char	*find_cmd(char *line);
void	run_cmd_here_doc(char **cmd, char **envp, int fd);
void	run_cmd_bonus(char *argv, char **envp, int fd);

#endif