# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 11:10:28 by pcottet           #+#    #+#              #
#    Updated: 2020/10/14 14:49:12 by pcottet          ###   ########.fr        #
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

# SRC_MEM		= ft_memset ft_bzero.c ft_calloc ft_memcpy.c			\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c

SRC_LIST	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c			\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c			\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS		= ${SRC_STR} ${SRC_STR_IS} ${SRC_STR_TO} ${SRC_PUT}		\
			${SRC_MEM}

SRCS_BONUS	= ${SRC_LIST}

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRC_BONUS:.c=.o}

INCL		= -include libft.h

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

COUNT 		= 1

${NAME}:	${OBJS}
			@${AR} ${NAME} $^
			@ranlib ${NAME}
			@echo "Done !"
			@echo "Library built\n----------------"

.c.o:
			@echo -n .
			@${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME} bonus
			@echo "Library and bonuses built\n----------------"

bonus:		${OBJS_BONUS}
			${AR} ${NAME} $^
			ranlib ${NAME}
			@echo "Bonuses built\n----------------"

clean:
			@${RM} ${OBJS} ${OBJS_BONUS}
			@echo "Objects cleaned\n----------------"

fclean:		clean
			@${RM} ${NAME}
			@echo "File cleaned\n----------------"

re:			fclean ${NAME}
			@echo "All Done"

.PHONY:		all clean fclean re bonus