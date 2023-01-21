/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:00 by anmande           #+#    #+#             */
/*   Updated: 2023/01/21 12:32:20 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define WIDTH       1080
#define LENGTH      ( WIDTH + 100 )

# include  "../mlx_linux/mlx.h"
# include <libft.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
}				t_data;

void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_loop (void *mlx_ptr);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		ft_close_win(t_data *man);
int 	mlx_loop_end (void *mlx_ptr);
#endif