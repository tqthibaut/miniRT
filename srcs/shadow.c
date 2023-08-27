/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:11:29 by tthibaut          #+#    #+#             */
/*   Updated: 2022/05/03 13:42:26 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	intersection_sphere_bool(t_data *data, t_vector normale,
	double distance, t_vector pos_p)
{
	double		b;
	double		c;
	double		t;
	t_sphere	*sphere;
	double		delta;

	sphere = data->sphere;
	delta = -1;
	while (sphere)
	{
		b = 2 * scalaire(normale, sub_vec(pos_p, sphere->origin));
		c = norm2(sub_vec(pos_p, sphere->origin))
			- sphere->rayon * sphere->rayon;
		delta = b * b - 4 * c;
		if (delta > 0)
		{
			t = (-b - sqrt(delta)) / 2;
			if (t > 0 && t < distance)
				return (TRUE);
		}
		sphere = sphere->next;
	}
	return (FALSE);
}

int	intersection_plan_bool(t_data *data, t_vector normale,
	double distance, t_vector pos_p)
{
	t_plan	*plan;
	double	t;

	plan = data->plan;
	t = -123;
	while (plan)
	{
		t = scalaire(sub_vec(plan->d1, pos_p), plan->d2)
			/ scalaire(normale, plan->d2);
		if (t <= 0.005f)
			return (FALSE);
		if (t > 0.005f && t < distance)
		{
			return (TRUE);
		}
		plan = plan->next;
	}
	return (FALSE);
}

int	is_shadow(t_data *data, t_infos infos)
{
	t_vector	p_l;
	t_vector	normale;
	double		distance;

	p_l = sub_vec(data->light->pos, infos.pos);
	if (data->light->intensity == 0.0)
		return (FALSE);
	distance = distance_ab(infos.pos, data->light->pos);
	normale = normalize(p_l);
	if (scalaire(sub_vec(data->light->pos, infos.pos), infos.norm) < 0)
		return (FALSE);
	if (intersection_sphere_bool(data, normale, distance, infos.pos) == TRUE)
		return (TRUE);
	if (intersection_cyl_bool(data, normale, distance, infos.pos) == TRUE)
		return (TRUE);
	if (intersection_plan_bool(data, normale, distance, infos.pos) == TRUE)
		return (TRUE);
	return (FALSE);
}
