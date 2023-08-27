/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:33 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/08 00:52:42 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	temp;

	if (*str2 == '\0' || str2 == NULL)
		return ((char *)str1);
	i = 0;
	while (i < n && str1[i])
	{
		temp = 0;
		while ((i + temp < n) && str2[temp] == str1[i + temp])
		{
			if (str2[temp + 1] == '\0')
				return ((char *)str1 + i);
			temp++;
		}
		i++;
	}
	return (0);
}
