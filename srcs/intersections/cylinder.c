/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:56:53 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 11:04:45 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_infos	infos_cyl_body(double temp, t_cylinder *cyl, t_ray ray)
{
	t_infos		infos;
	t_vector	dir;
	t_vector	p;

	dir = normalize(sub_vec(cyl->base_a, cyl->base_b));
	infos.t = temp;
	infos.color = cyl->colors;
	infos.pos = add_vec(ray.origin, mul_vec(infos.t, ray.direction));
	p = cross(sub_vec(infos.pos, cyl->base_b), dir);
	infos.norm = cross(dir, p);
	infos.norm = normalize(infos.norm);
	return (infos);
}

t_infos	infos_cyl_caps(double temp3, t_cylinder *cyl, t_ray ray)
{
	t_infos		infos;
	t_vector	dir;
	t_vector	p_center;

	p_center = div_vec(add_vec(cyl->base_a, cyl->base_b), 2);
	dir = normalize(sub_vec(cyl->base_a, cyl->base_b));
	infos.t = temp3;
	infos.color = cyl->colors;
	infos.pos = add_vec(ray.origin, mul_vec(infos.t, ray.direction));
	p_center = sub_vec(infos.pos, p_center);
	infos.norm = dir;
	if (scalaire(p_center, infos.norm) < 0)
		infos.norm = mul_vec(-1, infos.norm);
	return (infos);
}

t_infos	cyl_conditions(t_cyl_form cf, t_cylinder *cyl, t_ray ray, double *temp2)
{
	t_infos	infos;

	infos.a = 0;
	if (cf.y > 0 && cf.y < cf.ca2 && cf.temp > 0)
		infos = infos_cyl_body(cf.temp, cyl, ray);
	else
	{
		cf.temp = (cf.ca2 - cf.caoc) / cf.card;
		if (cf.y < 0.0)
			cf.temp = -cf.caoc / cf.card;
		if (fabs(cf.b + cf.a * cf.temp) < sqrt(cf.delta) && cf.temp > 0)
			infos = infos_cyl_caps(cf.temp, cyl, ray);
		else
			*temp2 = 200;
	}
	return (infos);
}

t_infos	intersection_cylinder(t_data *data, int i, int j, t_infos infos)
{
	t_ray		ray;
	t_cylinder	*cyl;
	t_cyl_form	cf;

	cyl = data->cyl;
	ray = create_rays(data, i, j);
	infos.t = 0.0;
	double (temp2) = 200;
	while (cyl)
	{
		cf = cylinder_formula(ray, cyl);
		if (cf.delta > 0 && cf.temp <= temp2)
		{
			temp2 = cf.temp;
			infos = cyl_conditions(cf, cyl, ray, &temp2);
		}
		cyl = cyl->next;
	}
	if (infos.t > 0)
		return (infos);
	infos.t = 0.0;
	return (infos);
}
