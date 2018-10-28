# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 23:37:53 by osavytsk          #+#    #+#              #
#    Updated: 2018/10/29 01:23:12 by osavytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
RM = rm -Rf
LIBFT = libftprintf/libft.a

SRC = lemin.c error_manag.c area_manipul.c\
valid_info.c read_info.c valid_areas.c setup_area.c\
exploration.c search_ways.c reloc_ant.c valid_binds.c

SRCDIR = srcs/
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJ = $(SRCS:.c=.o)
HEADERS = libftprintf/get_next_line.h lem_in.h 
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\r\033[48;5;15;38;5;25m 💣  Ready  $(NAME) \033[0m\033[K"

$(OBJ): %.o: %.c lem_in.h
	@$(CC) $(FLAGS) -I. -c $< -o $@
	@printf "\r\033[38;5;11m 🏳️‍🌈  Making %s     :  %s\033[0m\033[K" $(NAME) "$@"

$(LIBFT):
	@make -C libftprintf/

clean:
	@$(RM) $(OBJ)
	@make -C libftprintf/ clean
	@echo "\r\033[38;5;202m 🗑  clean $(NAME)\033[0m\033[K"

fclean: clean
	@$(RM) $(NAME)
	@make -C libftprintf/ fclean
	@echo "\r\033[38;5;196m ❌ fclean $(NAME)\033[0m\033[K"

re: fclean all

.PHONY: clean fclean re
