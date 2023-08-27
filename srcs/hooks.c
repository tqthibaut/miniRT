/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:14:42 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 11:57:39 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	keys(int key, t_data *data)
{
	if (key == XK_Up)
	{
		data->camera->origin.y -= 2;
		redraw(data);
		draw_shapes(data);
	}
	if (key == XK_Down)
	{
		data->camera->origin.y += 2;
		redraw(data);
		draw_shapes(data);
	}
	if (key == XK_Left)
	{
		data->camera->origin.x -= 2;
		redraw(data);
		draw_shapes(data);
	}
	else
		keys2(key, data);
	return (0);
}

int	keys2(int key, t_data *data)
{
	if (key == XK_Right)
	{
		data->camera->origin.x += 2;
		redraw(data);
		draw_shapes(data);
	}
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx.mlx, data->img.img);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		free_struct(data);
		exit(1);
	}
	return (0);
}
