# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 11:10:28 by pcottet           #+#    #+#              #
#    Updated: 2020/10/19 02:48:28 by pcottet          ###   ########.fr        #
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

SRC_MEM		= ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c			\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c

SRC_LIST	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c			\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c			\
			ft_lstclear.c ft_lstiter.c

SRCS		= ${SRC_STR} ${SRC_STR_IS} ${SRC_STR_TO} ${SRC_PUT}		\
			${SRC_MEM}

SRCS_BONUS	= ${SRC_LIST}

ifneq (${MAKECMDGOALS}, ${filter ${MAKECMDGOALS}, re})
ifeq (${MAKECMDGOALS}, ${filter ${MAKECMDGOALS},all reall})
	OBJS		= ${SRCS:.c=.o}

	OBJS		+= ${SRCS_BONUS:.c=.o}

	TARGET		= Library and bonus

	TOTAL		= 43

else ifeq (${MAKECMDGOALS}, bonus)
	OBJS		= ${SRCS_BONUS:.c=.o}

	TARGET		= Bonus

	TOTAL		= 9
else
	default		:=${shell echo "Unknown argument, try:\n all clean fclean re bonus reall test"}
endif
else
	OBJS		= ${SRCS:.c=.o}

	TARGET		= Library

	TOTAL		= 34
endif

COUNT		= 1
INCL		= -include libft.h
CC			= gcc
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m

${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@ranlib ${NAME}
			@echo "\n$(OK_COLOR)Done ✓"
			@echo "${TARGET} built$(NO_COLOR)\n----------------"

.c.o:
			@echo -n '${COUNT}/${TOTAL} '
			@${CC} -c ${CFLAGS} ${INCL} $< -o ${<:.c=.o}
			$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

bonus:		${NAME}

all:		${NAME}

clean:
			@${RM} *.o
			@echo "Objects cleaned\n----------------"

fclean:		clean
			@${RM} ${NAME}
			@echo "File cleaned\n----------------"

re:			fclean ${NAME}

reall:		fclean all

list:
			@echo "List of all arguments:"
			@echo "\t- make->(Build Library)\n\t- fclean->(Delete exec then clean)\n\t- clean->(Delete .o)\n\t- re->(fclean then make)\n\t- bonus->(Build only bonus)\n\
\t- all->(Build Library and Bonus)\n\t- reall->(fclean then all)\n\t- test->(Build libft with main.c, check_diff_error.c and fsanitize g3)"

test:
			@${CC} -fsanitize=address -g3 -L. -lft main.c check_diff_error.c && ./a.out
# echo "You can run a.out to test everything or select which part you want to test with one of those arguments:\n"
# echo "STR STR_IS STR_TO PUT MEM\nBONUS MORE"

.PHONY:		all clean fclean re bonus reall test list
