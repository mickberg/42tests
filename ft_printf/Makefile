# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/02/04 15:57:29 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := ft_printf_test.out

# Directories, library
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
LIB_DIR := ./../../
INC_DIR := ./includes/

# libft archive file name
LIB := ft
FTLIB := $(LIB_DIR)ftprintflib.a

# Files, library
SRC_FILES := \
	main_test.c

SRCS := $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(FTLIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(FTLIB) $(INC_DIR)ft_printf_test.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(LIB_DIR)includes/ -I $(INC_DIR) -L$(LIB_DIR) -lftprintf

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -g -o $@ -I $(INC_DIR) -I $(LIB_DIR)includes/

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
