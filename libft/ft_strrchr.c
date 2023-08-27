/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:34:10 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/07 22:55:16 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*j;
	int		i;

	i = 0;
	j = (char *)s;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (j[i] == c)
			return (&j[i]);
		i--;
	}
	return (0);
}
