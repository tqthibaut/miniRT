/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:00:21 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 17:44:15 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	i = 0;
	j = start;
	if (s == NULL)
		return (0);
	if (start < ft_strlen(s))
		while (s[j++] && i < len)
			i++;
	j = 0;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	while (j < i)
	{
		str[j++] = s[start++];
	}
	str[j] = '\0';
	return (str);
}
