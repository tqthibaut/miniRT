/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:01:59 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 18:46:25 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_char_count(const char *s1, const char *set)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (ft_is_set(set, s1[start]) && s1[start])
		start++;
	if (s1[start] == '\0')
		return (0);
	while (s1[end])
		end++;
	while (ft_is_set(set, s1[end - 1]) && end >= 0)
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	char	*news;

	if (!set || !s1)
		return (NULL);
	start = 0;
	i = 0;
	news = malloc(sizeof(char) * ft_char_count(s1, set) + 1);
	if (!news)
		return (NULL);
	while (ft_is_set(set, s1[start]) && s1[start])
		start++;
	while (i < ft_char_count(s1, set))
	{
		news[i] = s1[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}
