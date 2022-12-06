/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:05:34 by omsanfor          #+#    #+#             */
/*   Updated: 2022/06/22 16:05:35 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *str, unsigned int s, size_t l)
{
	size_t	i;
	size_t	k;
	char	*res;

	if (!str)
		return (0);
	if (ft_strlen(str) <= s)
		return (ft_strdup(""));
	if (ft_strlen(str) < (s + l))
		l = ft_strlen(str) - s;
	res = malloc((sizeof(char) * (l + 1)));
	if (!res)
		return (NULL);
	k = 0;
	if (ft_strlen((char *)str) > s)
	{
		i = s;
		while (str[i] && k < l)
			res[k++] = str[i++];
		res[k] = '\0';
		return (res);
	}
	res[k] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (haystack == needle || ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (haystack[i] != '\0' && len > i)
	{
		n = 0;
		while (needle[n] != '\0' && haystack[i + n] == needle[n]
			&& i + n < len && haystack[i + n] != '\0')
			n++;
		if (n == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
