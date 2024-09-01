# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/09/01 01:43:12 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBFT_A = libft.a

SRC = push_swap.c push.c reverse_rotate.c rotate.c swap.c validation.c sort.c \
      ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c sort_small_stack.c ft_lstupdateindx.c \
      ft_lstlast.c ft_lstmin.c ft_lstnew.c ft_lstsize.c ft_lstlastprev.c ft_split.c \
      calc_cost.c check_direction.c find_successor.c ft_putstr.c ft_lstmax.c ft_puterror.c \
      ft_lstgetindex.c rotate_direction.c ft_lstprint.c ft_atoi.c ft_isdigit.c \
      ft_substr.c ft_calloc.c ft_strlen.c ft_strdup.c ft_memcpy.c ft_memset.c ft_strtol.c \
      ft_freearray.c ft_isint.c ft_isempty.c ft_lstissorted.c ft_tablen.c ft_issorted.c

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
	@echo "$(RED)Removing the executable and the library...$(RESET)"
	rm -f $(NAME) $(LIBFT_A)

re: fclean all