/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:28:04 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 17:53:13 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_int(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
	}
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*dest;
	unsigned int	nb;

	i = ft_size_int(n);
	dest = malloc((sizeof(char)) * (i + 1));
	if (!dest)
		return (0);
	if (n < 0)
	{
		nb = n * (-1);
		dest[0] = '-';
	}
	else
		nb = n;
	if (n == 0)
		dest[0] = '0';
	dest[i--] = '\0';
	while (nb != 0)
	{
		dest[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	return (dest);
}
