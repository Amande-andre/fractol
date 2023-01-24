/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/01/24 17:46:13 by anmande          ###   ########.fr       */
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
	int		x_pos;
	int		y_pos;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	h;
}				t_data;

typedef struct s_comp
{
	double	re;
	double	im;
}				t_comp;


void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_loop (void *mlx_ptr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		ft_close_win(t_data *man);
int 	mlx_loop_end (void *mlx_ptr);
int		ft_print_mande(t_data *man, int color);
int		ft_conv(t_data *man, int i, int j);
int		set_data_man(t_data *man);
double	ft_sqr_re(double z_re, double c_re);
double	ft_sqr_im(double z_im, double c_im);


#endif