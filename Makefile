# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 13:19:28 by ansebast          #+#    #+#              #
#    Updated: 2024/08/16 15:27:38 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

SRC = $(filter-out $(BONUS_SRC), $(wildcard ft_*.c))
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Creating the library $(NAME)...$(RESET)"
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) successfully created!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	@echo "$(RED)Removing the library $(NAME)...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)Library $(NAME) successfully removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re