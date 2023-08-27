/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:20:02 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/07 23:49:37 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*j;

	j = (char *)s;
	while (*j != '\0')
	{
		if (*j == c)
			return (j);
		j++;
	}
	if (*j == '\0' && c == '\0')
		return (j);
	return (NULL);
}
