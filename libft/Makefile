# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 04:48:54 by chtang            #+#    #+#              #
#    Updated: 2024/01/10 02:09:18 by chtang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror

STRSRCS = ft_strlen.c \
	ft_substr.c ft_strlcat.c ft_strnstr.c \
	ft_strjoin.c ft_strncmp.c ft_split.c

MEMSRCS = ft_calloc.c ft_bzero.c

PRINTSRCS = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c

FREESRCS = ft_free.c ft_freearray.c

SRCS = ${STRSRCS} ${MEMSRCS} $(PRINTSRCS) ${FREESRCS}
OBJS = ${SRCS:%.c=%.o}
AR = ar rcs
RM = rm -rf

$(NAME) : $(OBJS)
	$(AR) $@ $^

.PHONY : all
all : $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

.PHONY : clean
clean :
	$(RM) $(OBJS)

.PHONY : fclean
fclean : clean
	$(RM) $(NAME)

.PHONY : re
re : fclean all
