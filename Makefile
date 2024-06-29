# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flboulea <flboulea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:41:13 by flboulea          #+#    #+#              #
#    Updated: 2024/06/07 02:29:54 by flboulea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a


#######################
######  SOURCES  ######
#######################

SRCS_DIR	= src
SRCS		= get_next_line.c		get_next_line_utils.c

FILES		= ${addprefix ${SRCS_DIR}/,${SRCS}}


########################
######  INCLUDES  ######
########################

INC_DIR		= include
INC_FLAGS	= $(addprefix -I ,$(INC_DIR))


#######################
######  OBJECTS  ######
#######################

OBJS_DIR	= objs
OBJS		= ${FILES:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}


###########################
######  COMPILATION  ######
###########################

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBC		= ar rc
LIBR		= ranlib

RM			= rm -rf


#####################
######  RULES  ######
#####################

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${dir $@}
	${CC} -c ${CFLAGS} ${INC_FLAGS} $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
