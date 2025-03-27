# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 17:30:30 by vpushkar          #+#    #+#              #
#    Updated: 2025/03/27 14:45:37 by vpushkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final static library
NAME = libftprintf.a

# Directory where the libft repository will be cloned
LIBFT_DIR = libft

# URL of the libft repository
LIBFT_REPO = https://github.com/Vspaceman11/libft_42.git

# Source, object and include directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# Include directories for compiling (libft and your project includes)
INCLUDE = -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

# List of source files for ft_printf
SRC = ft_printf.c ft_printf_chars.c ft_printf_pointers.c \
	ft_printf_puthex_fd.c ft_printf_putnbr_fd.c
# Add the path to the source files (from the src directory)
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

# List of object files generated from source files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Command to remove files or directories
RM = rm -rf

# Default rule (make all): build libft and then build the final libftprintf.a
all: $(LIBFT_DIR)/libft.a $(NAME)

# Rule to clone the libft repository if it's not present
$(LIBFT_DIR):
	git clone $(LIBFT_REPO) $(LIBFT_DIR)

# Rule to build the libft static library
$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)/Makefile
# Run make in the libft directory to build libft
	$(MAKE) -C $(LIBFT_DIR)

# Rule to ensure that libft Makefile is cloned (if needed)
$(LIBFT_DIR)/Makefile:
# Clone libft repository if it's not already there
	git clone $(LIBFT_REPO) $(LIBFT_DIR)

# Rule to compile source files into object files (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to create the final static library (.a) from object files
$(NAME): $(LIBFT_DIR)/libft.a $(OBJ_DIR) $(OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $@ $(OBJ)

# Rule to clean object files and directories
clean:
	$(RM) $(OBJ_DIR)
# Clean libft objects by running 'make clean' inside the libft directory
	$(MAKE) -C $(LIBFT_DIR) clean

# Rule to clean everything: remove object files and the final library
fclean: clean
	$(RM) $(NAME)
# Clean libft library by running 'make fclean' inside the libft directory
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to rebuild everything: clean and then build again
re: fclean all

# Mark these targets as 'phony', meaning they don't correspond to actual files
.PHONY: all clean fclean re
