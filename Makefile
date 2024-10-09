# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/10/09 22:56:07 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBSRC = ./libft
LIBFT = $(LIBSRC)/libft.a

SRC = push_swap.c push.c reverse_rotate.c rotate.c swap.c validation.c sort.c \
	sort_small_stack.c calc_cost.c check_direction.c find_successor.c rotate_direction.c
OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

INCLUDES = -I$(LIBSRC)
LIBRARY = -L$(LIBSRC)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBSRC) -lft -I$(LIBSRC) -o $(NAME) 
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(LIBFT):
#	@echo "$(YELLOW)Creating the library libft.a ...$(RESET)"
	@make bonus -C $(LIBSRC)
#	@echo "$(GREEN)Library created successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	@make clean -C $(LIBSRC)
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Removing the executable and the library...$(RESET)"
	@make fclean -C $(LIBSRC)
	rm -f $(NAME)

re: fclean all