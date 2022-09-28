# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 11:33:56 by ftuncer           #+#    #+#              #
#    Updated: 2022/09/21 11:29:05 by ftuncer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= mini_shell.a
APP		= mini_shell
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
MFILES	= $(wildcard ./sources/*.c)
MOBJ	= $(MFILES:%.c=%.o)

all		:  $(NAME) run

libft_m	:
	@make -C sources/libft

$(NAME) : $(MOBJ)
	@ar -rcs $(NAME) $(MOBJ)
	
run		: $(MOBJ)  libft_m
	$(CC) -o $(APP) $(CFLAGS) $(NAME) -lreadline -L/goinfre/ftuncer/homebrew/opt/readline/lib -I/goinfre/ftuncer/homebrew/opt/readline/include sources/libft/libft.a

clean	:
	@rm -rf *.o
	@rm -rf sources/*.o
	@rm -rf $(APP)

fclean	: clean
	@rm -rf $(NAME) 
	@make fclean -C sources/libft
	
re : fclean all

.PHONY: all run clean fclean re
