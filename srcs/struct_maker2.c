/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_maker2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:53:59 by tthibaut          #+#    #+#             */
/*   Updated: 2022/05/03 11:54:37 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	make_cylinder_next(char **tab, t_cylinder *tmp)
{
	tmp->x = ft_atodb(tab[1]);
	tmp->y = ft_atodb(tab[2]);
	tmp->z = ft_atodb(tab[3]);
	tmp->height = ft_atodb(tab[8]);
	tmp->rot.x = ft_atodb(tab[4]);
	tmp->rot.y = ft_atodb(tab[5]);
	tmp->rot.z = ft_atodb(tab[6]);
	tmp->rot = normalize(tmp->rot);
	tmp->base_a.x = tmp->x + tmp->rot.x * tmp->height / -2;
	tmp->base_a.y = tmp->y + tmp->rot.y * tmp->height / -2;
	tmp->base_a.z = tmp->z + tmp->rot.z * tmp->height / -2;
	tmp->rayon = ft_atodb(tab[7]) / 2;
	tmp->colors.r = (int)ft_atodb(tab[9]);
	tmp->colors.g = (int)ft_atodb(tab[10]);
	tmp->colors.b = (int)ft_atodb(tab[11]);
	tmp->base_b.x = tmp->x + tmp->rot.x * tmp->height / 2;
	tmp->base_b.y = tmp->y + tmp->rot.y * tmp->height / 2;
	tmp->base_b.z = tmp->z + tmp->rot.z * tmp->height / 2;
}

int	make_cylinder(char **tab, t_data *data)
{
	t_cylinder	*tmp;

	if (data->cyl == NULL)
	{
		data->cyl = malloc(sizeof(t_cylinder));
		if (!data->cyl)
			return (print_error("malloc failure\n"));
		data->cyl->next = NULL;
		tmp = data->cyl;
	}
	else
	{
		tmp = data->cyl;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_cylinder));
		if (!tmp->next)
			return (print_error("malloc failure\n"));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	make_cylinder_next(tab, tmp);
	return (TRUE);
}

void	make_plan_next(char **tab, t_plan *tmp)
{
	tmp->x = ft_atodb(tab[1]);
	tmp->y = ft_atodb(tab[2]);
	tmp->z = ft_atodb(tab[3]);
	tmp->d1.x = tmp->x;
	tmp->d1.y = tmp->y;
	tmp->d1.z = tmp->z;
	tmp->or_x = ft_atodb(tab[4]);
	tmp->or_y = ft_atodb(tab[5]);
	tmp->or_z = ft_atodb(tab[6]);
	tmp->d2.x = tmp->or_x;
	tmp->d2.y = tmp->or_y;
	tmp->d2.z = tmp->or_z;
	tmp->colors.r = (int)ft_atodb(tab[7]);
	tmp->colors.g = (int)ft_atodb(tab[8]);
	tmp->colors.b = (int)ft_atodb(tab[9]);
}

int	make_plan(char **tab, t_data *data)
{
	t_plan	*tmp;

	if (data->plan == NULL)
	{
		data->plan = malloc(sizeof(t_plan));
		if (!data->plan)
			return (print_error("malloc failure\n"));
		data->plan->next = NULL;
		tmp = data->plan;
	}
	else
	{
		tmp = data->plan;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_plan));
		if (!tmp->next)
			return (print_error("malloc failure\n"));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	make_plan_next(tab, tmp);
	return (TRUE);
}

int	make_light(char **tab, t_data *data)
{
	if (data->light != NULL)
		return (print_error("too many light parameters\n"));
	data->light = malloc(sizeof(t_light));
	if (data->light == NULL)
		return (print_error("malloc failure\n"));
	data->light->pos.x = ft_atodb(tab[1]);
	data->light->pos.y = ft_atodb(tab[2]);
	data->light->pos.z = ft_atodb(tab[3]);
	data->light->intensity = ft_atodb(tab[4]);
	if (tab[5])
	{
		data->light->color.r = ft_atodb(tab[5]);
		data->light->color.g = ft_atodb(tab[6]);
		data->light->color.b = ft_atodb(tab[7]);
	}
	else
	{
		data->light->color.r = 255;
		data->light->color.g = 255;
		data->light->color.b = 255;
	}
	return (TRUE);
}
