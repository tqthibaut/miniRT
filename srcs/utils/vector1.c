/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:13:15 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/16 17:58:41 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vector	add_vec(t_vector a, t_vector b)
{
	t_vector	vector;

	vector.x = a.x + b.x;
	vector.y = a.y + b.y;
	vector.z = a.z + b.z;
	return (vector);
}

t_vector	sub_vec(t_vector a, t_vector b)
{
	t_vector	vector;

	vector.x = a.x - b.x;
	vector.y = a.y - b.y;
	vector.z = a.z - b.z;
	return (vector);
}

t_vector	mul_vec(double a, t_vector b)
{
	t_vector	vector;

	vector.x = a * b.x;
	vector.y = a * b.y;
	vector.z = a * b.z;
	return (vector);
}

t_vector	div_vec(t_vector a, double b)
{
	t_vector	vector;

	vector.x = a.x / b;
	vector.y = a.y / b;
	vector.z = a.z / b;
	return (vector);
}
