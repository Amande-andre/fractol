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

SRCDIR		= 	srcs/
SRC			=	fractol.c julia.c move.c param.c tools.c windows.c			\

B_SRCDIR	= 	bonus/
B_SRC		=	fractol.c julia.c move.c param.c tools.c windows.c bonus.c	\

OBJDIR		= 	obj/
OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

B_OBJDIR	= 	bonus_obj
B_OBJ		= 	$(addprefix $(B_OBJDIR), $(B_SRC:.c=.o))

NAME		= 	fractol
B_NAME		= 	fractol_bonus

LIBFT		=	./libft
MLX			=	./mlx

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror -g

$(OBJDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(B_OBJDIR)%.o:	$(B_SRCDIR)%.c
					@mkdir -p $(B_OBJDIR)
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJ)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(B_NAME):		$(B_OBJ)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(B_OBJ) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(B_NAME)

all:			$(NAME) $(B_NAME)

bonus:			$(B_NAME)

clean:
					$(RM) -r $(OBJDIR)
					$(RM) -r $(B_OBJDIR)
					cd $(LIBFT) && $(MAKE) clean
					cd $(MLX) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(B_NAME)
					touch a.o
					rm *.o

re:				fclean all

.PHONY:			all bonus clean fclean re norminette


# ##### Colors ####
# GREEN 	= \033[0;32m
# RED 	= \033[0;31m
# BLUE 	= \033[0;34m
# END	= \033[0m

# ##### Names #####
# NAME	= fractol
# LIBNAME	= libft.a
# MLX_DIR = mlx
# MLX_PATH = ./mlx/libmlx.a
# CC	= cc
# CFLAGS	= -Wall -Werror -Wextra -g -Iminilibx-linux -O3
# MFLAGS = $(MLX_PATH) -lXext -lX11
# MLX_MAKE = Makefile

# SRCSDIR	= srcs
# OBJSDIR	= objs
# INCDIR	= inc
# LIBDIR	= libft

# _SRCS	= fractol.c tools.c move.c julia.c param.c windows.c
# SRCS	= $(addprefix $(SRCSDIR)/, $(_SRCS))
# OBJS	= $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
# HEADER = $(addprefix $(INCDIR)/, $(NAME).h)

# ##### Makefile work ####

# $(OBJSDIR)/%.o:$(SRCSDIR)/%.c $(HEADER)
# 	@mkdir -p $(OBJSDIR)
# 	$(CC) -c $(CFLAGS) -I$(LIBDIR) -I$(INCDIR) -I$(MLX) -Imlx -c $< -o $@

# $(NAME): $(OBJS) $(HEADER) $(MLX_PATH)
# 	@echo "Making $(LIBDIR)..."
# 	@make -s -C $(LIBDIR)
# 	@echo "$(GREEN)OK!$(END)"
# 	@echo "Making $(NAME)..."
# 	@$(CC) -I$(INCDIR) -I$(LIBDIR) $(OBJS) -o $(NAME) $(MFLAGS)
# 	@echo "$(GREEN)OK!$(END)"
# 	@echo "$(BLUE)READY !$(END)"
	
# all: $(NAME) 

# $(MLX_PATH):
# 	make -C ${MLX_DIR}

# clean:
# 	@echo "Removing objects..."
# 	@make clean -s -C $(LIBDIR)
# 	make clean -C ${MLX_DIR}
# 	@rm -r $(OBJSDIR) || true
# 	@echo "$(GREEN)Done!$(END)"

# fclean: clean
# 	@echo "Cleaning everything..."
# 	@make fclean -s -C $(LIBDIR)
# 	@rm -f $(NAME)
# 	@rm -f $(B_NAME)
# 	@echo "$(GREEN)Done!$(END)"
# 	@echo "$(BLUE)Everything is clean!$(END)"

# re:	fclean all

# .PHONY: all clean fclean re
