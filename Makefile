# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:39:02 by abouhlel          #+#    #+#              #
#    Updated: 2021/12/14 11:13:15 by abouhlel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			philo

# ███████╗    ██╗    ██╗         ███████╗    ███████╗
# ██╔════╝    ██║    ██║         ██╔════╝    ██╔════╝
# █████╗      ██║    ██║         █████╗      ███████╗
# ██╔══╝      ██║    ██║         ██╔══╝      ╚════██║
# ██║         ██║    ███████╗    ███████╗    ███████║
# ╚═╝         ╚═╝    ╚══════╝    ╚══════╝    ╚══════╝

FOLDER_HEADER		= includes/
FOLDER				= srcs/

HEADER_FILE 		= philosophers.h

SRCS				= 	philosophers.c \
						ft_utils.c \
						ft_error.c \
						ft_print.c \
						ft_memory.c

SRC					= $(addprefix ${FOLDER},${SRCS})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJ					= ${SRC:.c=.o}

#  ██████╗     ██████╗     ███╗   ███╗    ██████╗     ██╗    ██╗
# ██╔════╝    ██╔═══██╗    ████╗ ████║    ██╔══██╗    ██║    ██║
# ██║         ██║   ██║    ██╔████╔██║    ██████╔╝    ██║    ██║
# ██║         ██║   ██║    ██║╚██╔╝██║    ██╔═══╝     ██║    ██║
# ╚██████╗    ╚██████╔╝    ██║ ╚═╝ ██║    ██║         ██║    ███████╗
#  ╚═════╝     ╚═════╝     ╚═╝     ╚═╝    ╚═╝         ╚═╝    ╚══════╝

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror #-pthread #-g -fsanitize=address 
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C
UNAME_S				= $(shell uname -s)

COMPIL	= $(CC) $(CFLAGS) ${OBJ} -o $(NAME)

# ██████╗     ██╗   ██╗    ██╗         ███████╗    ███████╗
# ██╔══██╗    ██║   ██║    ██║         ██╔════╝    ██╔════╝
# ██████╔╝    ██║   ██║    ██║         █████╗      ███████╗
# ██╔══██╗    ██║   ██║    ██║         ██╔══╝      ╚════██║
# ██║  ██║    ╚██████╔╝    ███████╗    ███████╗    ███████║
# ╚═╝  ╚═╝     ╚═════╝     ╚══════╝    ╚══════╝    ╚══════╝

$(NAME):	${OBJ}
			@printf $(blue)
			@printf "\n"
			@printf $(magenta)
			@$(COMPIL)
			@printf $(green)
			@printf "🍽  HAPPY PHILOSOPHER GAMES 🍽 \n"
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf " Generating philosophers objects... %-33.33s\r" $@
			@$(CC) -c $(CFLAGS) -o $@ $<
			@printf $(reset)

re: 		fclean all

clean:
			@${RM} ${OBJ}
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf $(reset)

fclean:		clean
			@${RM} $(NAME)
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf $(reset)

.PHONY: 	all clean fclean re


#  ██████╗     ██████╗     ██╗          ██████╗     ██████╗
# ██╔════╝    ██╔═══██╗    ██║         ██╔═══██╗    ██╔══██╗
# ██║         ██║   ██║    ██║         ██║   ██║    ██████╔╝
# ██║         ██║   ██║    ██║         ██║   ██║    ██╔══██╗
# ╚██████╗    ╚██████╔╝    ███████╗    ╚██████╔╝    ██║  ██║
#  ╚═════╝     ╚═════╝     ╚══════╝     ╚═════╝     ╚═╝  ╚═╝


black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"

bg_black 			=	"[40m"
bg_red 				=	"[41m"
bg_green 			=	"[42m"
bg_yellow 			=	"[43m"
bg_blue 			=	"[44m"
bg_magenta 			=	"[45m"
bg_cyan 			=	"[46m"
bg_white 			=	"[47m"

reset 				=	"[0m"

#################################################################################
#                                                                               #
#                   ##                                             #####        #
#                   ##                                             #            #
#                   ##                                           #######        #
#                   ##                                              ##          #
#       #####       ##          ####           #    #    #          ##          #
#       #           ##         #    #          #    #    #          ##          #
#     ########      ########################### #### ####           ##          #
#                                                                               #
#################################################################################