/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:13:38 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 10:51:17 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_colors	ambiant_light(t_data *data, t_infos infos)
{
	t_colors	color;

	color.r = ((data->amb_lgt->color.r + infos.color.r) / 2)
		* data->amb_lgt->intensity;
	color.g = ((data->amb_lgt->color.g + infos.color.g) / 2)
		* data->amb_lgt->intensity;
	color.b = ((data->amb_lgt->color.b + infos.color.b) / 2)
		* data->amb_lgt->intensity;
	return (color);
}

void	shadow(t_data *data, t_infos infos, int i, int j)
{
	t_colors	color;

	if (is_shadow(data, infos) == TRUE)
	{
		color.r = ((data->amb_lgt->color.r + infos.color.r) / 2)
			* (data->amb_lgt->intensity / 2);
		color.g = ((data->amb_lgt->color.g + infos.color.g) / 2)
			* (data->amb_lgt->intensity / 2);
		color.b = ((data->amb_lgt->color.b + infos.color.b) / 2)
			* (data->amb_lgt->intensity / 2);
		pixel_put(&data->img, i, j, (color.r << 16)
			+ (color.g << 8) + (color.b));
	}
}

void	light_sphere(t_data *data, t_infos infos, int i, int j)
{
	t_colors	color;
	double		dir_light;

	color = ambiant_light(data, infos);
	dir_light = 400000 * data->light->intensity
		* scalaire(normalize(sub_vec(data->light->pos, infos.pos)), infos.norm)
		/ norm2(sub_vec(data->light->pos, infos.pos));
	if (dir_light > 255)
		dir_light = 255;
	if (dir_light < 0)
		dir_light = 0;
	color.r += (dir_light / 255) * ((data->light->color.r + infos.color.r) / 2);
	color.g += (dir_light / 255) * ((data->light->color.g + infos.color.g) / 2);
	color.b += (dir_light / 255) * ((data->light->color.b + infos.color.b) / 2);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	pixel_put(&data->img, i, j, (color.r << 16) + (color.g << 8) + (color.b));
	shadow(data, infos, i, j);
}

void	light_plan(t_data *data, t_infos infos, int i, int j)
{
	t_colors	color;
	double		dir_light;

	color = ambiant_light(data, infos);
	dir_light = 400000 * data->light->intensity
		* scalaire(normalize(sub_vec(data->light->pos, infos.pos)), infos.norm)
		/ norm2(sub_vec(data->light->pos, infos.pos));
	dir_light = fabs(dir_light);
	if (dir_light > 255)
		dir_light = 255;
	if (dir_light < 0)
		dir_light = 0;
	color.r += (dir_light / 255) * ((data->light->color.r + infos.color.r) / 2);
	color.g += (dir_light / 255) * ((data->light->color.g + infos.color.g) / 2);
	color.b += (dir_light / 255) * ((data->light->color.b + infos.color.b) / 2);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	pixel_put(&data->img, i, j, (color.r << 16) + (color.g << 8) + (color.b));
	shadow(data, infos, i, j);
}

void	light_cylinder(t_data *data, t_infos infos, int i, int j)
{
	t_colors	color;
	double		dir_light;

	color = ambiant_light(data, infos);
	dir_light = 400000 * data->light->intensity
		* scalaire(normalize(sub_vec(data->light->pos, infos.pos)), infos.norm)
		/ norm2(sub_vec(data->light->pos, infos.pos));
	if (dir_light > 255)
		dir_light = 255;
	if (dir_light < 0)
		dir_light = 0;
	color.r += (dir_light / 255) * ((data->light->color.r + infos.color.r) / 2);
	color.g += (dir_light / 255) * ((data->light->color.g + infos.color.g) / 2);
	color.b += (dir_light / 255) * ((data->light->color.b + infos.color.b) / 2);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	pixel_put(&data->img, i, j, (color.r << 16) + (color.g << 8) + (color.b));
	shadow(data, infos, i, j);
}
