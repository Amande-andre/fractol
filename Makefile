# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile 	                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:39:23 by anmande           #+#    #+#              #
#    Updated: 2023/02/06 10:28:28 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Colors ####
GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END	= \033[0m

##### Names #####
NAME	= fractol
B_NAME	= fractol_bonus
LIBNAME	= libft.a
MLX_DIR = mlx_linux
MLX_PATH = ./mlx_linux/libmlx.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g -Iminilibx-linux
MFLAGS = $(MLX_PATH) -lXext -lX11
MLX_MAKE = Makefile

SRCSDIR	= srcs
B_SRCSDIR = bonus
OBJSDIR	= objs
B_OBJSDIR = bonus_objs
INCDIR	= inc
LIBDIR	= libft

_SRCS	= fractol.c tools.c move.c julia.c param.c windows.c
SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
B_SRCS	= fractol.c tools.c move.c julia.c param.c bonus.c windows.c
B_SRCS	= $(addprefix $(B_SRCSDIR)/, $(B__SRCS))
OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
B_OBJS	= $(B_SRCS:$(B_SRCSDIR)%.c=$(OBJSDIR)%.o)
HEADER = $(addprefix $(INCDIR)/, $(NAME).h)
B_HEADER = $(addprefix $(INCDIR)/, $(B_NAME).h)

##### Makefile work ####

$(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(OBJSDIR)
	$(CC) -c $(CFLAGS) -I$(LIBDIR) -I$(INCDIR) -I$(MLX_LINUX) -Imlx_linux -c $< -o $@

$(B_OBJSDIR)/%.o:$(B_SRCSDIR)/%.c $(HEADER)
	@mkdir -p $(B_OBJSDIR)
	$(CC) -c $(CFLAGS) -I$(LIBDIR) -I$(INCDIR) -I$(MLX_LINUX) -Imlx_linux -c $< -o $@
	
$(NAME): $(OBJS) $(HEADER) $(MLX_PATH)
	@echo "Making $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Making $(NAME)..."
	@$(CC) -I$(INCDIR) -I$(LIBDIR) $(OBJS) -o $(NAME) $(MFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)READY !$(END)"

$(B_NAME): $(B_OBJS) $(HEADER) $(MLX_PATH)
	@echo "Making $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Making $(B_NAME)..."
	@$(CC) -I$(INCDIR) -I$(LIBDIR) $(B_OBJS) -o $(B_NAME) $(MFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)READY !$(END)"
	
all: $(NAME) $(B_NAME)

#bonus: $(B_NAME)

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
	@rm -f $(B_NAME)
	@echo "$(GREEN)Done!$(END)"
	@echo "$(BLUE)Everything is clean!$(END)"

re:	fclean all

.PHONY: all bonus clean fclean re