/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 21:49:16 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/14 18:00:50 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_gnl(char *str, int n)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	if (new == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*fill_line(char **str)
{
	int		len;
	char	*temp;
	char	*line;

	len = 0;
	while ((*str)[len] != '\0' && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
	{
		line = ft_strncpy_gnl(*str, ++len);
		temp = ft_strdup_gnl(&(*str)[len]);
		free(*str);
		*str = temp;
	}
	else
	{
		if (!**str)
			return (NULL);
		line = ft_else_gnl(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*manage_return_gnl(char **str, int ret, char *buf, int fd)
{
	char	*line;

	if (!buf)
		return (NULL);
	free(buf);
	if (fd < 0)
		return (NULL);
	if (ret < 0)
		return (NULL);
	else if (ret == 0 && *str == NULL)
		return (NULL);
	line = fill_line(&(*str));
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_cat_str_gnl(char *str, char *buf)
{
	char	*temp;

	temp = ft_strjoin(str, buf);
	if (temp == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
	str = temp;
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buf;
	int				ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = read(fd, buf, BUFFER_SIZE);
	if (buf == NULL || fd < 0)
		return (manage_return_gnl(&str, ret, buf, fd));
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup_gnl(buf);
		else
		{
			str = ft_cat_str_gnl(str, buf);
			if (str == NULL)
				return (NULL);
		}
		if (ft_strchr_gnl(str, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (manage_return_gnl(&str, ret, buf, fd));
}
