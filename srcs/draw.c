/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:42:36 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 10:56:54 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_ray	create_rays(t_data *data, int i, int j)
{
	t_ray		ray;
	double		fov;
	t_camera	*camera;

	camera = data->camera;
	fov = (camera->fov * M_PI) / 180;
	ray.origin.x = camera->origin.x;
	ray.origin.y = camera->origin.y;
	ray.origin.z = camera->origin.z;
	ray.direction.x = i - (WIDTH / 2);
	ray.direction.y = j - (HEIGHT / 2);
	ray.direction.z = WIDTH / 2 / fabs(tan(fov / 2));
	ray.direction = normalize(ray.direction);
	ray.direction = rotate_vec(ray.direction, camera->direction);
	ray.direction = normalize(ray.direction);
	return (ray);
}

void	put_color(t_data *data, t_g_infos g, int i, int j)
{
	if (g.a.t <= 0 && g.b.t <= 0 && g.c.t <= 0)
		return ;
	else if (g.a.t > 0 && (g.a.t <= g.b.t || g.b.t == 0)
		&& (g.a.t <= g.c.t || g.c.t == 0))
		light_plan(data, g.a, i, j);
	else if (g.b.t > 0 && (g.b.t <= g.a.t || g.a.t == 0)
		&& (g.b.t <= g.c.t || g.c.t == 0))
		light_sphere(data, g.b, i, j);
	else if (g.c.t > 0.0 && (g.c.t <= g.a.t || g.a.t == 0)
		&& (g.c.t <= g.b.t || g.b.t == 0))
		light_cylinder(data, g.c, i, j);
}

void	draw_shapes(t_data *data)
{
	int			j;
	t_g_infos	g;

	int (i) = 0;
	g.a.t = 0;
	g.b.t = 0;
	g.c.t = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (data->plan)
				g.a = intersection_plan(data, i, j);
			if (data->sphere)
				g.b = intersection_sphere(data, i, j);
			if (data->cyl)
				g.c = intersection_cylinder(data, i, j, g.c);
			put_color(data, g, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win, data->img.img, 0, 0);
}

void	redraw(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			pixel_put(&data->img, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win, data->img.img, 0, 0);
}
