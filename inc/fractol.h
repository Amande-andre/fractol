/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/02/06 13:31:43 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define Y_LEN		1200
#define X_LEN		(Y_LEN)
#define PRESS_ARROW_UP 65362
#define PRESS_ARROW_DOWN 65364
#define PRESS_ARROW_LEFT 65361
#define PRESS_ARROW_RIGHT 65363

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
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
	int 	set;
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
int		ft_param(t_data *f, char **av, int ac);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_julia_param(t_data *f, char *av);
int		ft_move_man(int key, t_data *f, int deltax, int deltay);
int		ft_print(t_data *f);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif