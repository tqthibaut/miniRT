/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:28:20 by tidurand          #+#    #+#             */
/*   Updated: 2022/04/25 17:42:18 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "./miniRT.h"

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}				t_colors;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_infos
{
	double		t;
	t_colors	color;
	t_vector	pos;
	t_vector	norm;
	int			a;
}				t_infos;

typedef struct s_g_infos
{
	t_infos		a;
	t_infos		b;
	t_infos		c;
}				t_g_infos;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

typedef struct s_sphere
{
	double			x;
	double			y;
	double			z;
	t_vector		origin;
	double			rayon;
	t_colors		colors;
	struct s_sphere	*next;

}				t_sphere;

typedef struct s_plan
{
	double			x;
	double			y;
	double			z;
	double			or_x;
	double			or_y;
	double			or_z;
	t_vector		d1;
	t_vector		d2;
	double			red;
	double			blue;
	double			green;
	t_colors		colors;
	struct s_plan	*next;
}				t_plan;

typedef struct s_cylinder
{
	double				x;
	double				y;
	double				z;
	double				or_x;
	double				or_y;
	double				or_z;
	double				diameter;
	double				rayon;
	double				height;
	double				red;
	double				blue;
	double				green;
	t_vector			base_a;
	t_vector			base_b;
	t_vector			rot;
	struct s_colors		colors;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct s_cyl_form
{
	t_vector	ca;
	t_vector	oc;
	double		ca2;
	double		card;
	double		caoc;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		temp;
	double		y;
}				t_cyl_form;

typedef struct s_camera
{
	double		x;
	double		y;
	double		z;
	t_vector	origin;
	t_vector	direction;
	double		fov;
}				t_camera;

typedef struct s_amb_light
{
	float		intensity;
	int			red;
	int			green;
	int			blue;
	t_colors	color;
}				t_amb_light;

typedef struct s_light
{
	float		x;
	float		y;
	float		z;
	float		intensity;
	int			flag_color;
	t_vector	pos;
	t_colors	color;
}				t_light;

typedef struct s_data {
	t_mlx		mlx;
	t_img		img;
	t_camera	*camera;
	t_amb_light	*amb_lgt;
	t_light		*light;
	t_sphere	*sphere;
	t_plan		*plan;
	t_cylinder	*cyl;
}				t_data;

typedef enum e_type_c
{
	AMBIANT_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	plan,
	CYLINDER
}				t_type_c;

#endif
