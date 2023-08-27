/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:04:37 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 11:06:05 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_cyl_form	cylinder_formula_2(t_cyl_form cf, t_ray ray)
{
	cf.ca.x += 0.001;
	cf.ca.y += 0.001;
	cf.ca.z += 0.001;
	cf.ca2 = scalaire(cf.ca, cf.ca);
	cf.card = scalaire(cf.ca, ray.direction);
	cf.a = cf.ca2 - cf.card * cf.card;
	return (cf);
}

t_cyl_form	cylinder_formula(t_ray ray, t_cylinder *cyl)
{
	t_cyl_form	cf;

	cf.ca = sub_vec(cyl->base_b, cyl->base_a);
	cf.oc = sub_vec(ray.origin, cyl->base_a);
	cf.ca2 = scalaire(cf.ca, cf.ca);
	cf.card = scalaire(cf.ca, ray.direction);
	cf.caoc = scalaire(cf.ca, cf.oc);
	cf.a = cf.ca2 - cf.card * cf.card;
	if (cf.a == 0.0)
		cf = cylinder_formula_2(cf, ray);
	cf.b = cf.ca2 * scalaire(cf.oc, ray.direction) - cf.caoc * cf.card;
	cf.c = cf.ca2 * scalaire(cf.oc, cf.oc)
		- cf.caoc * cf.caoc - cyl->rayon * cyl->rayon * cf.ca2;
	cf.delta = cf.b * cf.b - cf.a * cf.c;
	if (cf.delta > 0.0)
	{
		cf.temp = (-cf.b - sqrt(cf.delta)) / cf.a;
		cf.y = cf.caoc + cf.temp * cf.card;
	}
	else
		cf.y = 200;
	return (cf);
}
