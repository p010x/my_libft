# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 11:10:28 by pcottet           #+#    #+#              #
#    Updated: 2020/10/13 04:43:29 by pcottet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC_STR		= ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c		\
			ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c		\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c		\
			ft_strmapi.c

SRC_STR_IS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	\
			ft_isprint.c

SRC_STR_TO	= ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c

SRC_PUT		= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c		\
			ft_putnbr_fd.c

SRC_MEM		= ft_memset ft_bzero.c ft_calloc ft_memcpy.c			\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c

SRC_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c			\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c			\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS		= ${SRC_STR} ${SRC_STR_IS} ${SRC_STR_TO} ${SRC_PUT}		\
			${SRC_MEM}

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRC_BONUS:.c=.o}

INCL	= -include libft.h

CC		= gcc

AR		= ar rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:		${OBJS_BONUS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all 

.PHONY:		all clean fclean re ${NAME} bonus
