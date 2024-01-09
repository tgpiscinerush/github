# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:21:29 by chtang            #+#    #+#              #
#    Updated: 2024/01/10 04:11:32 by chtang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = libft/libft.a
CFLAG = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
SRCS = cmds.c pipe.c main.c errors.c cmds_ult.c
OBJS = ${SRCS:%.c=%.o}

all :
	${MAKE} -C libft
	make start

start : ${NAME}

${LIBFT} :
	${MAKE} -C libft

${NAME} : ${LIBFT} ${OBJS}
	${CC} ${OBJS} ${LIBFT} -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

rmobjs :
	${RM} ${OBJS}

clean : rmobjs
	${MAKE} clean -C libft

fclean : rmobjs
	$(RM) $(NAME)
	${MAKE} fclean -C libft

re : fclean all

.PHONY : re clean all fclean rmobjs
