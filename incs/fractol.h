/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/02/02 18:18:23 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define Y_LEN		1200
#define X_LEN		(Y_LEN)
#define PRESS_ARROW_UP 65362
#define PRESS_ARROW_DOWN 65364
#define PRESS_ARROW_LEFT 65361
#define PRESS_ARROW_RIGHT 65363

# include  "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include "../mlx_linux/mlx_int.h"

typedef struct s_comp
{
	long double	re;
	long double	im;
}				t_comp;

typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		itteration;
	int		h;
	int		xp;
	int		yp;
	double	x;
	double	y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	double	delta;
	int		color;
	t_comp	c;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close_win(int key, t_data *f);
int		ft_print_mande(t_data *f);
int		ft_conv(t_data *f, double i, double j);
int		set_data_man(t_data *f);
int		ft_close_win2(t_data *f);
int		ft_zoom(int x, int y, t_data *f);
int		ft_dezoom(int x, int y, t_data *f);
int		ft_mouse_hook(int code, int x, int y, t_data *f);
int		ft_move(int key, t_data *f);
int		ft_conv_julia(t_data *f, double i, double j);
int		ft_julia_loop(t_data *f);
int		ft_print_julia(t_data *f);
int		ft_param(t_data *f, char *av);

#endif