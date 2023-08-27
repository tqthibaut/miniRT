/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:13:15 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/26 12:34:32 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

double	scalaire(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	norm2(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

t_vector	normalize(t_vector a)
{
	double	norm;

	norm = sqrt(norm2(a));
	a.x /= norm;
	a.y /= norm;
	a.z /= norm;
	return (a);
}

t_vector	cross(t_vector a, t_vector b)
{
	t_vector	vector;

	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	return (vector);
}

double	distance_ab(t_vector a, t_vector b)
{
	double	distance;

	distance = powf((a.x - b.x), 2) + powf((a.y - b.y), 2)
		+ powf((a.z - b.z), 2);
	distance = sqrt(distance);
	return (distance);
}
