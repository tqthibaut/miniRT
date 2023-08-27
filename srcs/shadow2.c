/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:31:47 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 10:56:25 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_cyl_form	cylinder_formula2(t_vector normale, t_vector pos_p, t_cylinder *cyl)
{
	t_cyl_form	cf;

	cf.ca = sub_vec(cyl->base_b, cyl->base_a);
	cf.oc = sub_vec(pos_p, cyl->base_a);
	cf.ca2 = scalaire(cf.ca, cf.ca);
	cf.card = scalaire(cf.ca, normale);
	cf.caoc = scalaire(cf.ca, cf.oc);
	cf.a = cf.ca2 - cf.card * cf.card;
	cf.b = cf.ca2 * scalaire(cf.oc, normale) - cf.caoc * cf.card;
	cf.c = cf.ca2 * scalaire(cf.oc, cf.oc)
		- cf.caoc * cf.caoc - cyl->rayon * cyl->rayon * cf.ca2;
	cf.delta = cf.b * cf.b - cf.a * cf.c;
	return (cf);
}

int	inter_suite(t_cyl_form cf, double t, double distance)
{
	double	y;

	y = cf.caoc + t * cf.card;
	if (y > 0.0 && y < cf.ca2 && t < distance && t > __DBL_EPSILON__)
		return (TRUE);
	if (y < 0.0)
		t = -cf.caoc / cf.card;
	else
		t = (cf.ca2 - cf.caoc) / cf.card;
	if (fabs(cf.b + cf.a * t) < sqrt(cf.delta) && t < distance
		&& t > __DBL_EPSILON__)
		return (TRUE);
	return (FALSE);
}

int	intersection_cyl_bool(t_data *data, t_vector normale,
	double distance, t_vector pos_p)
{
	t_cylinder	*cyl;
	t_cyl_form	cf;
	double		t;

	cyl = data->cyl;
	while (cyl)
	{
		cf = cylinder_formula2(normale, pos_p, cyl);
		if (cf.delta >= 0.0)
			t = (-cf.b - sqrt(cf.delta)) / cf.a;
		else
		{
			cyl = cyl->next;
			continue ;
		}
		if (inter_suite(cf, t, distance) == TRUE)
			return (TRUE);
		cyl = cyl->next;
	}
	return (FALSE);
}
