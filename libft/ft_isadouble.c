/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isadouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:29:10 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/14 14:53:14 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_a_double(char *str)
{
	int		dot;

	dot = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '+')
		str++;
	if (*str == '-')
	{
		if (str[1] && (str[1] < '0' || str[1] > '9'))
			return (0);
		str++;
	}
	while (*str)
	{
		if (*str == '.')
			dot++;
		if ((*str > '9' || *str < '0') && *str != '.')
			return (0);
		str++;
	}
	if (*str != '\0' || dot > 1)
		return (0);
	return (1);
}
