/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 15:05:11 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define Y_LEN       1080
#define X_LEN      ( Y_LEN + 100 )

# include  "../mlx_linux/mlx.h"
# include <libft.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
	int		x_len;
	int		y_len;
	int		top;
	int		left;
}				t_data;

typedef struct s_comp
{
	long	real;
	long	unreal;
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
int		ft_conv(t_data *man, int x, int y);
#endif