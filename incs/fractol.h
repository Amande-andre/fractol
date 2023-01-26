/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/01/26 15:35:49 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define Y_LEN		1200
#define X_LEN		(Y_LEN)

# include  "../mlx_linux/mlx.h"
# include <libft.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include "../mlx_linux/mlx_int.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
	double	x;
	double	y;
	int		xp;
	int		yp;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	h;
	int		itteration;
	int		zoom;
	double	mvx;
	double	mvy;
}				t_data;

typedef struct s_comp
{
	double	re;
	double	im;
}				t_comp;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close_win(int key, t_data *man);
int		ft_print_mande(t_data *man, int color);
int		ft_conv(t_data *man, int i, int j);
int		set_data_man(t_data *man);
int		ft_close_win2(t_data *man);
int		ft_zoom(int x, int y, t_data *man);
int		ft_dezoom(int x, int y, t_data *man);
int		ft_mouse_hook(int code, int x, int y, t_data *man);

#endif