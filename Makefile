# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 17:52:51 by jerdos-s          #+#    #+#              #
#    Updated: 2022/08/13 18:05:27 by jerdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

OPTIONS = -c
CFLAGS = -Wall -Wextra -Werror

SRC_PATH_CLIENT = ./client_src/
SRC_PATH_SERVER = ./server_src/


SRC_CLIENT = client.c client_utils.c parse_arg.c send_message.c
SRC_SERVER = 

SRCS_CLIENT = $(addprefix $(SRC_PATH_CLIENT), $(SRC_CLIENT))
SRCS_SERVER = $(addprefix $(SRC_PATH_SERVER), $(SRC_SERVER))

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = gcc

all: $(CLIENT) $(SERVER)

.c.o:
	$(CC) $(CFLAGS) $(OPTIONS) $(<) -o $(<:.c=.o)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(SERVER)

clean:
	/bin/rm -f $(OBJS_CLIENT)
	/bin/rm -f $(OBJS_SERVER)

fclean: clean
	/bin/rm -f $(CLIENT)
	/bin/rm -f $(SERVER)


re: fclean all

.PHONY: re fclean clean all


