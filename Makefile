# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zoeschne <zoeschne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 16:18:11 by zoeschne          #+#    #+#              #
#    Updated: 2025/07/03 16:12:58 by zoeschne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###	ARGUMENTS	###
NAME		= push_swap
NAME_BONUS	= checker
CFLAGS		= -Wall -Werror -Wextra -O3
CC			= cc

###	SOURCES		###
SRCS		= main.c sort.c lis.c greedy.c lis_utils.c greedy_utils.c 						
OBJS		= $(SRCS:.c=.o)

COMMANDS	= push.c reverse_rotate.c rotate.c swap.c ft_split.c init_stack.c errors.c utils.c
COM_OBJS	= $(COMMANDS:.c=.o)

BONUS		= bonus/checker.c bonus/get_next_line_utils.c bonus/get_next_line.c
BONUS_OBJS	= $(BONUS:.c=.o)

###	RULES		###
all	: ${NAME} bonus

${NAME}	: ${OBJS} ${COM_OBJS}
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS} ${COM_OBJS}

bonus	: ${BONUS_OBJS} ${COM_OBJS}
	$(CC) $(CFLAGS) -o ${NAME_BONUS} ${BONUS_OBJS} ${COM_OBJS} 

clean	:
	rm -f ${OBJS} ${BONUS_OBJS} ${COM_OBJS}

fclean	: clean
	rm -f ${NAME} ${NAME_BONUS}

re	: fclean all

.PHONY	: all clean fclean re
