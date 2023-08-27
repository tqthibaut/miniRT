/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:42:07 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/23 13:40:28 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	print_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (ERROR);
}

int	check_doubles(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		if (ft_is_a_double(tab[i]) == FALSE)
		{
			ft_putstr_fd("Error: ", 2);
			ft_putstr_fd(tab[i], 2);
			ft_putstr_fd(" is not a valid parameter\n", 2);
			return (ERROR);
		}
		i++;
	}
	return (TRUE);
}

int	which_type(char *str)
{
	if (!str)
		return (ERROR);
	if (str[0] == 'A' && str[1] == '\0')
		return (AMBIANT_LIGHT);
	if (str[0] == 'C' && str[1] == '\0')
		return (CAMERA);
	if (str[0] == 'L')
		return (LIGHT);
	if (str[0] == 'p')
		if (str[1] && str[1] == 'l' && str[2] == '\0')
			return (plan);
	if (str[0] == 's' && str[1])
		if (str[1] == 'p' && str[2] == '\0')
			return (SPHERE);
	if (str[0] == 'c' && str[1])
		if (str[1] == 'y' && str[2] == '\0')
			return (CYLINDER);
	return (print_error("unknown type\n"));
}

int	checker_line(char **tab)
{
	int	i;
	int	type;

	i = 0;
	type = which_type(tab[0]);
	i = check_doubles(tab);
	if (type == ERROR || i == ERROR)
		return (ERROR);
	else if (type == AMBIANT_LIGHT)
		return (check_amb_light(tab));
	else if (type == CAMERA)
		return (check_cam(tab));
	else if (type == LIGHT)
		return (check_light(tab));
	else if (type == SPHERE)
		return (check_sphere(tab));
	else if (type == plan)
		return (check_plan(tab));
	else if (type == CYLINDER)
		return (check_cylinder(tab));
	else
		return (ERROR);
}
