# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:05:53 by omsanfor          #+#    #+#              #
#    Updated: 2022/06/22 16:05:54 by omsanfor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	src/pipex.c			src/utils.c			src/error.c\
			src/pipex_func.c	src/ft_split.c		src/open_file.c\
			src/get_next_line.c

SRCS_B	= 	bonus/pipex_bonus.c src/get_next_line.c src/pipex_func.c\
			src/ft_split.c		src/utils.c			src/error.c\
			src/open_file.c

HEADER	=	includes/pipex.h

OBJS	=	$(SRCS:%.c=%.o)

OBJSB	=	$(SRCS_B:%.c=%.o)

CC		=	gcc

INC		=	-I includes 

CFLAGS	=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY	:	all clean fclean re

all		:	$(NAME)

bonus	:	$(OBJSB) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(OBJSB) -o $(NAME)

clean	:
	@rm -f $(OBJS) $(OBJSB)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
