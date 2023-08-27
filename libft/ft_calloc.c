/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:59:03 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 18:05:27 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*output;

	i = 0;
	output = malloc(count * size);
	if (!output)
		return (0);
	while (i < (count * size))
	{
		((unsigned char *)output)[i] = 0;
		i++;
	}
	return (output);
}
