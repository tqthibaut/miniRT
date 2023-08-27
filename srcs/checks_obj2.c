/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_obj2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:27:17 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/26 14:17:50 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	color_check_cyl(char **tab)
{
	double	color[3];

	color[0] = ft_atodb(tab[9]);
	color[1] = ft_atodb(tab[10]);
	color[2] = ft_atodb(tab[11]);
	if (color[0] < 0.0f || color[0] > 255.0 || color[1] < 0.0f
		|| color[1] > 255.0f || color[2] < 0.0f || color[2] > 255.0f)
		return (print_error("value outside of range (color)\n"));
	return (TRUE);
}

int	check_cylinder(char **tab)
{
	int		tab_size;
	double	orient[3];
	double	diameter;
	double	height;

	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 12)
		return (ERROR);
	orient[0] = ft_atodb(tab[4]);
	orient[1] = ft_atodb(tab[5]);
	orient[2] = ft_atodb(tab[6]);
	if (orient[0] < -1.0f || orient[0] > 1.0f || orient[1] < -1.0f
		|| orient[1] > 1.0f || orient[2] < -1.0f || orient[2] > 1.0f)
		return (print_error("value outside of range\n"));
	diameter = ft_atodb(tab[7]);
	height = ft_atodb(tab[8]);
	if (diameter < 0.0f || height < 0.0f)
		return (print_error("value outside of range (diameter)\n"));
	return (color_check_cyl(tab));
}

int	check_all_struct(t_data *data)
{
	if (!data->amb_lgt)
		return (print_error("Missing AMB_LGT\n"));
	if (!data->camera)
		return (print_error("Missing CAM\n"));
	if (!data->light)
		return (print_error("Missing LIGHT\n"));
	return (TRUE);
}

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 3)
		return (print_error("Wrong file\n"));
	if (ft_strncmp(&str[i - 3], ".rt", 3) != 0)
		return (print_error("Wrong extension\n"));
	return (TRUE);
}
