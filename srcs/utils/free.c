/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:13:11 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/25 12:43:15 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_struct_next(t_data *data)
{
	t_cylinder	*tmp_cyl;
	t_plan		*tmp_plan;

	free(data->sphere);
	while (data->plan)
	{
		tmp_plan = data->plan->next;
		free(data->plan);
		data->plan = tmp_plan;
	}
	free(data->plan);
	while (data->cyl)
	{
		tmp_cyl = data->cyl->next;
		free(data->cyl);
		data->cyl = tmp_cyl;
	}
	free(data->cyl);
}

void	free_struct(t_data *data)
{
	t_sphere	*tmp_s;

	if (data->amb_lgt)
		free(data->amb_lgt);
	data->amb_lgt = NULL;
	if (data->camera)
		free(data->camera);
	data->camera = NULL;
	if (data->light)
		free(data->light);
	data->light = NULL;
	while (data->sphere)
	{
		tmp_s = data->sphere->next;
		free(data->sphere);
		data->sphere = tmp_s;
	}
	free_struct_next(data);
}
