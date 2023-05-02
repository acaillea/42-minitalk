# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 13:15:32 by acaillea          #+#    #+#              #
#    Updated: 2021/11/26 13:15:41 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC	= client
NAMES	= server

SRCC	= client.c
OBJC	= ${SRCC:.c=.o}

SRCS 	= server.c
OBJS	= ${SRCS:.c=.o}

SRCU	= utils.c
OBJU	= ${SRCU:.c=.o}

INC		= minitalk.h
FLAGS 	= -Wall -Werror -Wextra
CC 		= gcc
RM 		= rm -f

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all: ${NAMEC} ${NAMES}

${NAMEC}: ${OBJC} ${OBJU}
	@${CC} ${FLAGS} ${OBJC} ${OBJU} -o ${NAMEC}
	@printf "\e[32;3m<----------------------->\e[0m\n"
	@printf "\e[32;3m$@ Successfully Build\e[0m\n"

${NAMES}: ${OBJS} ${OBJU}
	@${CC} ${FLAGS} ${OBJS} ${OBJU} -o ${NAMES}
	@printf "\e[32;3m<----------------------->\e[0m\n"
	@printf "\e[32;3m$@ Successfully Build\e[0m\n"
	@printf "\e[32;3m<----------------------->\e[0m\n"

clean:
	@${RM} ${OBJC} ${OBJS} ${OBJU}
	@printf "\e[31;3m	Clean files\e[0m\n"

fclean: clean
	@${RM} ${NAMEC} ${NAMES}
	@printf "\e[31;3m	Clean exec\e[0m\n"
	@printf "\e[31;3m^^^^^^^^^^^^^^^^^^^^^^^^^\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
