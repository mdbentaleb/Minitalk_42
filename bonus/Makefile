# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 19:43:33 by moben-ta          #+#    #+#              #
#    Updated: 2025/02/12 18:14:43 by moben-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFALGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER= server_b
NAME_CLIENT = client_b

SRC_SERVER = server_bonus.c ../utils/utils.c
SRC_CLIENT = client_bonus.c ../utils/utils.c

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)


LIBFTPRINTF = ../ft_printf/libftprintf.a

OUT_DIR ?= .

# ------------- bonus ---------------- #
all: $(OUT_DIR)/$(NAME_SERVER) $(OUT_DIR)/$(NAME_CLIENT)

$(LIBFTPRINTF):
	@$(MAKE) -C ../ft_printf


$(OUT_DIR)/$(NAME_SERVER): $(OBJS_SERVER) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(OUT_DIR)/$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@$(MAKE) -C ../ft_printf clean


fclean: clean
	@rm -f $(OUT_DIR)/$(NAME_SERVER) $(OUT_DIR)/$(NAME_CLIENT)
	@$(MAKE) -C ../ft_printf fclean

re: fclean all

.PHONY: clean