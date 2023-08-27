/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:56:45 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/26 12:40:46 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_infos	infos_sphere(double temp, t_sphere *sphere, t_ray ray)
{
	t_infos	infos;

	infos.t = temp;
	infos.color = sphere->colors;
	infos.pos = add_vec(ray.origin, mul_vec(infos.t, ray.direction));
	infos.norm = normalize(sub_vec(infos.pos, sphere->origin));
	return (infos);
}

double	delta_positive(double a, double b, double delta)
{
	double	x1;
	double	x2;
	double	temp;

	temp = 0.0;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (x1 < x2 && x1 > 0.000001)
		temp = x1;
	else if (x2 > 0.000001 && (x1 > x2 || x1 <= 0.000001))
		temp = x2;
	else if (x1 < 0.000001 && x2 < 0.000001)
		temp = -122;
	return (temp);
}

double	make_temp(t_ray ray, t_sphere *sphere)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		temp;

	a = norm2(ray.direction);
	b = 2.0 * scalaire(ray.direction, sub_vec(ray.origin, sphere->origin));
	c = norm2(sub_vec(ray.origin, sphere->origin)) - pow(sphere->rayon, 2);
	delta = b * b - (4.0 * a * c);
	if (delta > 0.0)
		temp = delta_positive(a, b, delta);
	else
		temp = -123;
	return (temp);
}

t_infos	intersection_sphere(t_data *data, int i, int j)
{
	t_ray		ray;
	t_sphere	*sphere;
	double		temp;
	t_infos		infos;

	ray = create_rays(data, i, j);
	sphere = data->sphere;
	infos.t = -123;
	infos.color = sphere->colors;
	while (sphere)
	{
		temp = make_temp(ray, sphere);
		if (infos.t <= 0)
			infos = infos_sphere(temp, sphere, ray);
		if (infos.t > 0 && (temp > 0 && temp < infos.t))
			infos = infos_sphere(temp, sphere, ray);
		sphere = sphere->next;
	}
	if (infos.t > 0)
		return (infos);
	infos.t = 0;
	return (infos);
}
