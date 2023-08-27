/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:53:24 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 18:03:37 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	size_source;
	size_t	size_dest;

	size_source = ft_strlen(src);
	size_dest = ft_strlen(dest);
	i = 0;
	if (size <= size_dest)
		return (size + size_source);
	if (size == 0)
		return (0);
	while (dest[i] && i < size)
		i++;
	n = i;
	while ((i < (size - 1)) && src[i - n] != '\0')
	{
		dest[i] = src[i - n];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (size_source + size_dest);
}
