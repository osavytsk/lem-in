# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 23:21:15 by osavytsk          #+#    #+#              #
#    Updated: 2018/10/28 23:40:20 by osavytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
LIB_PATH = ./libft/

SRC_LIB = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
 ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c\
 ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
 ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
 ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
 ft_putstr.c ft_putstr_fd.c ft_sort_tab.c ft_strcat.c\
 ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
 ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c\
 ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c

SRC_PF = converter_base.c final_write.c ft_printf.c initialize_flags.c\
 type_char.c type_dec.c type_oct.c type_str.c type_hex.c type_float.c get_next_line.c

OBJ_LIB = $(addprefix $(LIB_PATH), $(SRC_LIB:.c=.o))
OBJ_PF = $(SRC_PF:.c=.o)
OBJ = $(OBJ_LIB) $(OBJ_PF)
FLAGS = -Wall -Wextra -Werror
RM = rm -Rf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\r\033[48;5;15;38;5;25m 💣  Ready libft.a \033[0m\033[K"

$(OBJ_LIB): %.o: %.c get_next_line.h
	@$(CC) $(FLAGS) -I . -c $< -o $@
	@printf "\r\033[38;5;11m 🏳️‍🌈  Making %s     :  %s\033[0m\033[K" $(NAME) "$@"

$(OBJ_PF): %.o: %.c get_next_line.h
	@$(CC) $(FLAGS) -I . -c $< -o $@
	@printf "\r\033[38;5;11m 🏳️‍🌈  Making %s     :  %s\033[0m\033[K" $(NAME) "$@"

clean:
	@$(RM) $(OBJ)
	@echo "\r\033[38;5;202m 🗑  clean $(NAME)\033[0m\033[K"

fclean: clean
	@$(RM) $(NAME)
	@echo "\r\033[38;5;196m ❌ fclean $(NAME)\033[0m\033[K"

re: fclean all

.PHONY: clean fclean re
