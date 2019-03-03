# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 17:36:58 by qsebasti          #+#    #+#              #
#    Updated: 2018/01/24 13:02:39 by qsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re createlib

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_NAME = main.c \
		   ft_set.c \
		   ft_hook.c \
		   ft_draw.c \
		   ft_bonus.c

SRC_PATH = src

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC = -I ./inc/

LIB = libft/

LFT = -L ./$(LIB) -lft

MLX = minilibx_macos/

FRAMEWORK = -L ./$(MLX) -lmlx -framework OpenGL -framework AppKit -lm

RM = /bin/rm -f

all: createlib $(OBJ_PATH) $(NAME)

createlib:
	make -C $(MLX)
	make -C $(LIB)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(FRAMEWORK) $(LFT) $(INC)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c inc/fdf.h
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

clean:
	make -C $(MLX) clean
	make -C $(LIB) clean
	$(RM) -r $(OBJ_PATH)

fclean: clean
	make -C $(LIB) fclean
	$(RM) $(NAME)

re: fclean all
