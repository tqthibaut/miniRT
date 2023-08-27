/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:30:41 by tthibaut          #+#    #+#             */
/*   Updated: 2022/01/11 17:46:36 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	long int	nb;
	int			signe;

	nb = 0;
	signe = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		nb *= 10;
		nb = nb + (*str - 48);
		if (nb > 2147483647 && signe == 1)
			return (-1);
		if (nb > 2147483648 && signe == -1)
			return (0);
		str++;
	}
	return ((int)(nb * signe));
}
