# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 16:05:14 by jpedra-v          #+#    #+#              #
#    Updated: 2026/05/25 16:05:19 by jpedra-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = codexion
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -pthread

SRCS        = coders/main.c \
              coders/heap_queue.c \
              coders/destroy.c \
              coders/create_thread.c \
              coders/create_mutex.c \
              coders/chained_queue.c \
              coders/scheduler_fifo.c \
              coders/scheduler_edf.c \
              coders/monitoring.c \
              coders/logs.c \
              coders/dongles_management.c \
              coders/coder.c \
              coders/print_struct.c \
              coders/print_queue.c \
              coders/check_arguments.c \
              coders/check_time.c \
              coders/check_scheduler.c \
              coders/exit.c \
              coders/getter.c \
              coders/init_struct.c \
              coders/setter.c

OBJS        = $(SRCS:.c=.o)
HEADER      = codexion.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
