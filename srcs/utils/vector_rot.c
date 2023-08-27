/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:28:17 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/25 17:28:37 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/miniRT.h"

t_vector	vec_rotate_x(t_vector v, double ang)
{
	double		tmp_y;
	double		tmp_z;

	tmp_y = v.y;
	tmp_z = v.z;
	v.y = tmp_y * cos(ang) - tmp_z * sin(ang);
	v.z = tmp_y * sin(ang) + tmp_z * cos(ang);
	return (v);
}

t_vector	vec_rotate_y(t_vector v, double ang)
{
	double		temp_x;
	double		tmp_x;

	temp_x = v.x;
	tmp_x = v.z;
	v.z = tmp_x * cos(ang) - temp_x * sin(ang);
	v.x = tmp_x * sin(ang) + temp_x * cos(ang);
	return (v);
}

t_vector	vec_rotate_z(t_vector v, double ang)
{
	double		temp_x;
	double		tmp_y;

	temp_x = v.x;
	tmp_y = v.y;
	v.x = temp_x * cos(ang) - tmp_y * sin(ang);
	v.y = temp_x * sin(ang) + tmp_y * cos(ang);
	return (v);
}

t_vector	rotate_vec(t_vector v, t_vector rot)
{
	v = vec_rotate_y(v, rot.y * M_PI);
	v = vec_rotate_x(v, rot.x * M_PI);
	v = vec_rotate_z(v, rot.z * M_PI);
	return (v);
}

t_vector	unrotate_vec(t_vector v, t_vector rot)
{
	v = vec_rotate_y(v, rot.y * M_PI * -1);
	v = vec_rotate_x(v, rot.x * M_PI * -1);
	v = vec_rotate_z(v, rot.z * M_PI * -1);
	return (v);
}
