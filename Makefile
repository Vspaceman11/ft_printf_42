# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 14:13:04 by vpushkar          #+#    #+#              #
#    Updated: 2025/03/27 17:20:31 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = ft_printf.c \
	ft_printf_chars.c \
	ft_printf_putnbr_fd.c \
	ft_printf_pointers.c \
	ft_printf_puthex_fd.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC = $(INC_DIR)/libft.h
RM = rm -f

all: $(NAME)
# Create object directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Create static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(B_OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
