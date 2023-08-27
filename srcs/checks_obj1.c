/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_obj1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:18:18 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/25 17:15:13 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_amb_light(char **tab)
{
	int		tab_size;
	float	intensity;
	int		red;
	int		green;
	int		blue;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 5)
		return (print_error("amb light: wrong number of parameters\n"));
	intensity = ft_atof(tab[1]);
	if (intensity < 0.0 || intensity > 1.0)
		return (print_error("amb light: wrong range of parameter\n"));
	red = ft_atoi(tab[2]);
	green = ft_atoi(tab[3]);
	blue = ft_atoi(tab[4]);
	if (red < 0.0 || red > 255 || green < 0.0
		|| green > 255 || blue < 0.0 || blue > 255)
		return (print_error("amb light: wrong range of parameter\n"));
	return (TRUE);
}

int	check_cam(char **tab)
{
	int		tab_size;
	double	orient[3];
	double	fov;

	tab_size = 0;
	fov = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 8)
		return (ERROR);
	orient[0] = ft_atodb(tab[4]);
	orient[1] = ft_atodb(tab[5]);
	orient[2] = ft_atodb(tab[6]);
	if (orient[0] < -1.0 || orient[0] > 1.0 || orient[1] < -1.0
		|| orient[1] > 1.0 || orient[2] < -1.0 || orient[2] > 1.0)
		return (print_error("camera: wrong range of parameter\n"));
	fov = ft_atodb(tab[7]);
	if (fov < 0 || fov > 180)
		return (print_error("camera: wrong range of parameter\n"));
	if (fov == 180)
		return (print_error("fun fact : tan 90 is infinite\n"));
	return (TRUE);
}

int	check_light(char **tab)
{
	int		tab_size;
	double	ratio;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 8 && tab_size != 5)
		return (print_error("light: wrong number of parameters\n"));
	ratio = ft_atodb(tab[4]);
	if (ratio < 0.0 || ratio > 1.0)
		return (print_error("light: wrong range of parameter\n"));
	if (tab_size == 8)
	{
		if (ft_atoi(tab[5]) < 0 || ft_atoi(tab[5]) > 255 || ft_atoi(tab[6]) < 0
			|| ft_atoi(tab[6]) > 255 || ft_atoi(tab[7]) < 0
			|| ft_atoi(tab[7]) > 255)
			return (print_error("light: wrong range of parameter\n"));
	}
	return (TRUE);
}

int	check_sphere(char **tab)
{
	int		tab_size;
	double	color[3];
	double	diameter;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 8)
		return (ERROR);
	diameter = ft_atodb(tab[4]);
	if (diameter < 0)
		return (print_error("sphere: value outside of range\n"));
	color[0] = ft_atodb(tab[5]);
	color[1] = ft_atodb(tab[6]);
	color[2] = ft_atodb(tab[7]);
	if (color[0] < 0.0f || color[0] > 255.0f || color[1] < 0.0f
		|| color[1] > 255.0f || color[2] < 0.0f || color[2] > 255.0f)
		return (print_error("sphere: value outside of range\n"));
	return (TRUE);
}

int	check_plan(char **tab)
{
	int		tab_size;
	double	orient[3];
	double	color[3];

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 10)
		return (print_error("wrong number of parameters\n"));
	orient[0] = ft_atodb(tab[4]);
	orient[1] = ft_atodb(tab[5]);
	orient[2] = ft_atodb(tab[6]);
	if (orient[0] < -1.0f || orient[0] > 1.0f || orient[1] < -1.0f
		|| orient[1] > 1.0f || orient[2] < -1.0f || orient[2] > 1.0f)
		return (print_error("value outside of range\n"));
	color[0] = ft_atodb(tab[7]);
	color[1] = ft_atodb(tab[8]);
	color[2] = ft_atodb(tab[9]);
	if (color[0] < 0.0f || color[0] > 255.0f || color[1] < 0.0f
		|| color[1] > 255.0f || color[2] < 0.0f || color[2] > 255.0f)
		return (print_error("value outside of range\n"));
	return (TRUE);
}
