/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:23:09 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/26 14:06:56 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	quit(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->img.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	free_struct(data);
	exit(1);
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		return (1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "miniRT");
	if (data->mlx.mlx_win == NULL)
	{
		free(data->mlx.mlx_win);
		return (1);
	}
	data->img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	return (0);
}

void	init_data(t_data *data)
{
	data->amb_lgt = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->sphere = NULL;
	data->plan = NULL;
	data->cyl = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (parser(ac, av, &data) == ERROR || check_all_struct(&data) == ERROR)
	{
		free_struct(&data);
		return (ERROR);
	}
	if (init_mlx(&data) == 1)
		return (1);
	draw_shapes(&data);
	mlx_hook(data.mlx.mlx_win, 17, 0, quit, &data);
	mlx_key_hook(data.mlx.mlx_win, keys, &data);
	mlx_loop(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.img.img);
	mlx_destroy_window(data.mlx.mlx, data.mlx.mlx_win);
	mlx_destroy_display(data.mlx.mlx);
	free_struct(&data);
	return (0);
}
