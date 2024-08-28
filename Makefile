# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/08/28 10:14:22 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
LIBFT_A = libft.a

SRC = push_swap.c push.c reverse_rotate.c rotate.c swap.c validation.c sort.c \
      ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
      ft_lstlast.c ft_lstmin.c ft_lstnew.c ft_lstsize.c ft_lstprint.c ft_lstindex.c \
      ft_lstlastprev.c

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	@echo "$(YELLOW)Linking the objects...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lft
	@echo "$(GREEN)Executable $(NAME) created successfully!$(RESET)"

$(LIBFT_A): $(OBJ)
	@echo "$(YELLOW)Creating the library $(LIBFT_A)...$(RESET)"
	ar rcs $(LIBFT_A) $(OBJ)
	@echo "$(GREEN)Library $(LIBFT_A) created successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)File compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Removing the executables and libraries...$(RESET)"
	rm -f $(NAME) $(LIBFT_A)

re: fclean all

run: ./push_swap

.PHONY: all clean fclean re