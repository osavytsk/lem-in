# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 20:40:34 by osavytsk          #+#    #+#              #
#    Updated: 2018/10/27 05:12:44 by osavytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in
LIB		= libft/
FLAG	= -Wall -Wextra -Werror
RM		= rm -Rf
CC		= gcc
H		= ./includes/lemin.h
OT		= srcs/output/output
ADD		= srcs/additional/
VS		= srcs/visu/visu
SRCS	= srcs/lemin.c srcs/parseInput.c srcs/findAllPaths.c \
			srcs/removeAll.c srcs/buildMatrix.c srcs/getBestWays.c \
			srcs/searchDiff.c srcs/createAnts.c srcs/parseCom.c \
            $(ADD)addCommand.c $(ADD)addDiff.c $(ADD)addLink.c \
            $(ADD)addRoom.c $(ADD)addWay.c $(ADD)checkData.c \
            $(ADD)createInfo.c $(ADD)readFile.c \
            $(OT)AllWays.c $(OT)File.c $(OT)Result.c $(OT)Paths.c \
            $(OT)AntMoves.c $(OT)AntMovesAdd.c \
            $(VS)Diagonal.c $(VS)DiagonalChecks.c $(VS)PutLink.c \
            $(VS)PutMap.c $(VS)Line.c $(VS)AddDiagonal.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@$(CC) $(FLAG) $(OBJS) $(LIB)libft.a -o $(NAME)
	@printf "Ready: %s\n" $(NAME)

./srcs/%.o: ./srcs/%.c $(H)
	@printf "Compiling...\n"
	@$(CC) $(FLAG) -I $(H) -c $<  -o $@

clean:
	@printf "Removing: objects\n"
	@$(RM) $(OBJS)
	@make -C $(LIB) clean
	@printf "Ready\n"

fclean: clean
	@printf "Removing: %s libft.a\n" $(NAME)
	@$(RM) $(NAME)
	@make -C $(LIB) fclean
	@printf "Ready\n"

re: fclean all

.PHONY: clean fclean re
