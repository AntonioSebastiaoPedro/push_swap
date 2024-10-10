# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/10/10 08:20:09 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
BONUS = checker
LIBSRC = ./libft
LIBFT = $(LIBSRC)/libft.a

SRC = push_swap.c push.c reverse_rotate.c rotate.c swap.c validation.c sort.c \
	sort_small_stack.c calc_cost.c check_direction.c find_successor.c rotate_direction.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = checker_bonus.c  push_bonus.c  reverse_rotate_bonus.c  rotate_bonus.c  sort_bonus.c  swap_bonus.c  validation_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBSRC) -lft -I$(LIBSRC) -o $(NAME) 
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Creating the library libft.a ...$(RESET)"
	make bonus -C $(LIBSRC)
	@echo "$(GREEN)Library created successfully!$(RESET)"

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(LIBFT) 
	@echo "$(YELLOW)Linking the bonus objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBSRC) -lft -I$(LIBSRC) -o $(BONUS) 
	@echo "$(GREEN)Bonus executable $(BONUS) created successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	make clean -C $(LIBSRC)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "$(RED)Removing the executable and the library...$(RESET)"
	make fclean -C $(LIBSRC)
	rm -f $(NAME) $(BONUS)

re: fclean all

rebonus: fclean bonus