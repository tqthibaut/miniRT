/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:33:22 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/04 11:05:23 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "./types.h"

# define WIDTH 1200
# define HEIGHT 900
# define ERROR -1
# define FALSE 0
# define TRUE 1

//mlx
void		pixel_put(t_img *img, int x, int y, int color);

//hooks
int			keys(int key, t_data *data);
int			keys2(int key, t_data *data);
int			keys3(int key, t_data *data);
int			keys4(int key, t_data *data);

//vectors
t_vector	add_vec(t_vector a, t_vector b);
t_vector	sub_vec(t_vector a, t_vector b);
t_vector	mul_vec(double a, t_vector b);
t_vector	div_vec(t_vector a, double b);
double		scalaire(t_vector a, t_vector b);
double		norm2(t_vector a);
t_vector	normalize(t_vector a);
t_vector	cross(t_vector a, t_vector b);
double		distance_ab(t_vector a, t_vector b);
t_vector	rotate_vec(t_vector a, t_vector angle);
t_vector	unrotate_vec(t_vector a, t_vector angle);

//draw_shapes
void		redraw(t_data *data);
void		draw_shapes(t_data *data);

//intersections
t_infos		intersection_cylinder(t_data *data, int i, int j, t_infos c);
t_cyl_form	cylinder_formula(t_ray ray, t_cylinder *cyl);
t_infos		intersection_plan(t_data *data, int i, int j);
t_infos		intersection_sphere(t_data *data, int i, int j);

//light
void		light_sphere(t_data *data, t_infos infos, int i, int j);
void		light_plan(t_data *data, t_infos infos, int i, int j);
void		light_cylinder(t_data *data, t_infos infos, int i, int j);
int			is_shadow(t_data *data, t_infos infos);
int			intersection_cyl_bool(t_data *data, t_vector normale,
				double distance, t_vector pos_p);

//objects
t_ray		create_rays(t_data *data, int i, int j);
t_sphere	create_sphere(void);
t_cylinder	create_cylinder(void);
t_plan		create_plan(void);

// PARSER
int			parser(int ac, char **av, t_data *data);
int			structure_maker(char **tab, t_data *data);
int			which_type(char *str);
int			check_all_struct(t_data *data);

//ERROR
int			print_error(char *str);
void		free_struct(t_data *data);

//CHECKER
int			which_type(char *str);
int			checker_line(char **tab);
int			check_plan(char **tab);
int			check_sphere(char **tab);
int			check_light(char **tab);
int			check_cam(char **tab);
int			check_amb_light(char **tab);
int			check_cylinder(char **tab);
int			check_extension(char *str);

//STRUCT MAKER
int			make_cylinder(char **tab, t_data *data);
int			make_plan(char **tab, t_data *data);
int			make_light(char **tab, t_data *data);

//FREE
void		free_tab(char **tab);
void		free_struct(t_data *data);

#endif
