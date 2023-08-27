/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:24:23 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/26 14:26:00 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	make_amb_light(char **tab, t_data *data)
{
	if (data->amb_lgt != NULL)
		return (print_error("too many amb_light parameters\n"));
	data->amb_lgt = malloc(sizeof(t_amb_light));
	if (data->amb_lgt == NULL)
		return (print_error("malloc failure\n"));
	data->amb_lgt->intensity = ft_atodb(tab[1]);
	data->amb_lgt->color.r = (int)ft_atodb(tab[2]);
	data->amb_lgt->color.g = (int)ft_atodb(tab[3]);
	data->amb_lgt->color.b = (int)ft_atodb(tab[4]);
	return (TRUE);
}

int	make_camera(char **tab, t_data *data)
{
	if (data->camera != NULL)
		return (print_error("too many camera parameters\n"));
	data->camera = malloc(sizeof(t_camera));
	if (data->camera == NULL)
		return (print_error("malloc failure\n"));
	data->camera->origin.x = ft_atodb(tab[1]);
	data->camera->origin.y = ft_atodb(tab[2]);
	data->camera->origin.z = ft_atodb(tab[3]);
	data->camera->direction.y = ft_atodb(tab[4]);
	data->camera->direction.x = ft_atodb(tab[5]);
	data->camera->direction.z = ft_atodb(tab[6]);
	data->camera->fov = ft_atodb(tab[7]);
	return (TRUE);
}

void	make_sphere_next(char **tab, t_sphere *tmp)
{
	tmp->origin.x = ft_atodb(tab[1]);
	tmp->origin.y = ft_atodb(tab[2]);
	tmp->origin.z = ft_atodb(tab[3]);
	tmp->rayon = ft_atodb(tab[4]) / 2;
	tmp->colors.r = (int)ft_atodb(tab[5]);
	tmp->colors.g = (int)ft_atodb(tab[6]);
	tmp->colors.b = (int)ft_atodb(tab[7]);
}

int	make_sphere(char **tab, t_data *data)
{
	t_sphere	*tmp;

	if (data->sphere == NULL)
	{
		data->sphere = malloc(sizeof(t_sphere));
		if (!data->sphere)
			return (print_error("malloc failure\n"));
		data->sphere->next = NULL;
		tmp = data->sphere;
	}
	else
	{
		tmp = data->sphere;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_sphere));
		if (!tmp->next)
			return (print_error("malloc failure\n"));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	make_sphere_next(tab, tmp);
	return (TRUE);
}

int	structure_maker(char **tab, t_data *data)
{
	int	type;

	type = which_type(tab[0]);
	if (type == ERROR)
		return (ERROR);
	else if (type == AMBIANT_LIGHT)
		return (make_amb_light(tab, data));
	else if (type == CAMERA)
		return (make_camera(tab, data));
	else if (type == LIGHT)
		return (make_light(tab, data));
	else if (type == SPHERE)
		return (make_sphere(tab, data));
	else if (type == plan)
		return (make_plan(tab, data));
	else if (type == CYLINDER)
		return (make_cylinder(tab, data));
	else
		return (ERROR);
}
