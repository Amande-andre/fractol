# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 16:23:01 by anmande           #+#    #+#              #
#    Updated: 2023/01/18 12:32:45 by anmande          ###   ########.fr        #
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
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -g3

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
	$(CC) -c $(CFLAGS) -I$(INCSDIR) -I$(LIBDIR) $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "Making $(LIBDIR)..."
	@make -s -C $(LIBDIR)
	@echo "$(GREEN)OK!$(END)"
	@echo "Making $(NAME)..."
	@$(CC) -I$(INCSDIR) -I$(LIBDIR) -o $@ $^ $(LIBDIR)/$(LIBNAME) $(CFLAGS)
	@echo "$(GREEN)OK!$(END)"
	@echo "$(BLUE)READY !$(END)"

clean:
	@echo "Removing objects..."
	@make clean -s -C $(LIBDIR)
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
