/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/01/30 17:21:01 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define Y_LEN		1000
#define X_LEN		(Y_LEN)
# define PRESS_ARROW_UP 65362
# define PRESS_ARROW_DOWN 65364
# define PRESS_ARROW_LEFT 65361
# define PRESS_ARROW_RIGHT 65363
# include  "../mlx_linux/mlx.h"
# include <libft.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include "../mlx_linux/mlx_int.h"

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
}				t_data;

typedef struct s_comp
{
	double	re;
	double	im;
}				t_comp;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_close_win(int key, t_data *man);
int		ft_print_mande(t_data *man, int color);
int		ft_conv(t_data *man, double i, double j);
int		set_data_man(t_data *man);
int		ft_close_win2(t_data *man);
int		ft_zoom(int x, int y, t_data *man);
int		ft_dezoom(int x, int y, t_data *man);
int		ft_mouse_hook(int code, int x, int y, t_data *man);
int	ft_move(int key, t_data *man);
#endif