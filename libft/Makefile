# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:27:18 by qsebasti          #+#    #+#              #
#    Updated: 2019/03/03 18:12:40 by qsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY=all clean fclean re opti

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC_NAME=ft_memset.c \
		 ft_bzero.c \
		 ft_memcpy.c \
		 ft_memccpy.c \
		 ft_memmove.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_strlen.c \
		 ft_strdup.c \
		 ft_strcpy.c \
		 ft_strncpy.c \
		 ft_strcat.c \
		 ft_strncat.c \
		 ft_strlcat.c \
		 ft_strchr.c \
		 ft_strrchr.c \
		 ft_strstr.c \
		 ft_strnstr.c \
		 ft_strcmp.c \
		 ft_strncmp.c \
		 ft_atoi.c \
		 ft_isalpha.c \
		 ft_isdigit.c \
		 ft_isalnum.c \
		 ft_isascii.c \
		 ft_isprint.c \
		 ft_toupper.c \
		 ft_tolower.c \
		 ft_memalloc.c \
		 ft_memdel.c \
		 ft_strnew.c \
		 ft_strdel.c \
		 ft_strclr.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strmap.c \
		 ft_strmapi.c \
		 ft_strequ.c \
		 ft_strnequ.c \
		 ft_strsub.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_strsplit.c \
		 ft_itoa.c \
		 ft_putchar.c \
		 ft_putstr.c \
		 ft_putendl.c \
		 ft_putnbr.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_lstnew.c \
		 ft_lstdelone.c \
		 ft_lstdel.c \
		 ft_lstadd.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 ft_isspace.c \
		 ft_sqrt.c \
		 ft_swap.c \
		 ft_strrev.c \
		 ft_countw.c \
		 ft_lstlen.c \
		 ft_printtab.c \
		 ft_lstback.c \
		 ft_lstcreate.c \
		 ft_lstif.c \
		 ft_dellist.c \
		 ft_lstclean.c \
		 ft_new_alloc.c \
		 ft_nblen.c \
		 ft_freesplit.c \
		 get_next_line.c

SRC_PATH=src

SRC=$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME=$(SRC_NAME:.c=.o)

OBJ_PATH=obj

OBJ=$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC=-I inc/

RM=/bin/rm -f

opti:
	@make -j8 all

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)/%.o: %.c libft.h
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
	$(RM) $(OBJ) 
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re:
	@make fclean
	@make opti
