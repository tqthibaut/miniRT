/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:56:49 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/25 17:25:49 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_infos	infos_plan(double temp, t_plan *plan, t_ray ray, t_data *data)
{
	t_infos	infos;

	infos.t = temp;
	infos.color = plan->colors;
	infos.pos = add_vec(ray.origin, mul_vec(infos.t, ray.direction));
	infos.norm = plan->d2;
	if (scalaire(sub_vec(data->light->pos, infos.pos), infos.norm) < 0)
	{
		infos.norm.x *= -1;
		infos.norm.y *= -1;
		infos.norm.z *= -1;
	}
	return (infos);
}

t_infos	intersection_plan(t_data *data, int i, int j)
{
	t_ray	ray;
	t_plan	*plan;
	double	temp;
	t_infos	infos;

	ray = create_rays(data, i, j);
	plan = data->plan;
	infos.t = -123;
	infos.color = plan->colors;
	while (plan)
	{
		temp = -1 * scalaire(sub_vec(ray.origin, plan->d1), plan->d2)
			/ scalaire(ray.direction, plan->d2);
		if (infos.t <= 0)
			infos = infos_plan(temp, plan, ray, data);
		if (infos.t > 0 && (temp > 0 && temp < infos.t))
			infos = infos_plan(temp, plan, ray, data);
		plan = plan->next;
	}
	if (infos.t > 0)
		return (infos);
	infos.t = 0.0;
	return (infos);
}
