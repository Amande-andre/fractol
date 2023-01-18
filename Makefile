# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 16:47:31 by anmande           #+#    #+#              #
#    Updated: 2023/01/18 17:57:39 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 16:23:01 by anmande           #+#    #+#              #
#    Updated: 2023/01/18 16:48:40 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Colors ####
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END	= \033[0m

##### Names #####
NAME	= fractol
LIBNAME	= libft.a
MLX_DIR = mlx_linux
MLX_PATH = ./mlx_linux/libmlx.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -g -Iminilibx-linux
MFLAGS = $(MLX_PATH) -lXext -lX11
MLX_MAKE = Makefile

SRCSDIR	= srcs
OBJSDIR	= objs
INCSDIR	= incs
LIBDIR	= libft

_SRCS	= fractol.c 
SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
HEADER = $(addprefix $(INCSDIR)/, $(NAME).h)

##### Makefile work ####

$(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJSDIR)
	$(CC) -c $(CFLAGS) -I$(INCSDIR) -I$(LIBDIR) -I$(MLX_LINUX) -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(MLX_PATH)
	@echo "Making $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Making $(NAME)..."
	@$(CC) -I$(INCSDIR) -I$(LIBDIR) $(OBJS) -o $(NAME) $(MFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)READY !$(END)"

$(MLX_PATH):
	make -C ${MLX_DIR}


clean:
	@echo "Removing objects..."
	@make clean -s -C $(LIBDIR)
	make clean -C ${MLX_DIR}
	@rm -r $(OBJSDIR) || true
	@echo "$(GREEN)Done!$(END)"

fclean: clean
	@echo "Cleaning everything..."
	@make fclean -s -C $(LIBDIR)
	@rm -f $(NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BLUE)Everything is clean!$(END)"

re:	fclean all

.PHONY: all clean fclean re
