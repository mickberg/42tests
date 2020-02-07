# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/02/07 14:47:56 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./config.mk

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := ft_printf_test.out

# Directories, library
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
INC_DIR := ./includes/

# Files, library
SRC_FILES := \
	main_test.c \
	test_env.c \
	tests/test_int.c \
	utils/file_io.c

SRCS := $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))
OBJS := $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(INC_DIR)ft_printf_test.h
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR)  -I $(LIB_PATH) -I $(LIB_PATH)includes/ -L$(LIB_PATH) -l$(LIB_NAME:lib%.a=%)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -g -o $@ -I $(INC_DIR) -I $(LIB_PATH) -I $(LIB_PATH)includes/

clean:
	rm -rf $(OBJ_DIR)
	rm -rf *.txt

fclean: clean
	rm -f $(NAME)

re: fclean all
