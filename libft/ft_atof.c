/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:25:48 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/14 14:34:45 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	atof_decimal(char *s, int i, float value, float decimal)
{
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			value += (s[i] - '0') * decimal;
			decimal *= 0.1;
			i++;
		}
	}
	return (value);
}

float	ft_atof(char *s)
{
	float	value;
	float	decimal;
	int		i;
	char	sign;

	sign = 1;
	i = 0;
	value = 0;
	decimal = 0.1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		value = 10.0 * value + (s[i] - '0');
		i++;
	}
	value = atof_decimal(s, i, value, decimal);
	return (sign * value);
}
