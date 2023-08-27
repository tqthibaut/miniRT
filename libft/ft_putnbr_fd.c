/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:25:57 by tthibaut          #+#    #+#             */
/*   Updated: 2021/03/06 13:57:13 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	li;
	int			i;

	li = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		li = li * (-1);
	}
	if (li >= 0)
	{
		i = li % 10 + 48;
		li = li / 10;
		if (li > 0)
		{
			ft_putnbr_fd(li, fd);
		}
		write(fd, &i, 1);
	}
}
