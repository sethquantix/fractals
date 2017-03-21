# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 05:13:49 by cchaumar          #+#    #+#              #
#    Updated: 2017/03/21 05:30:56 by cchaumar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = viewer
BIN    = ./
CFLG   = -Wextra -Wall -Werror -g -fsanitize=address
FILES  = main.c utils.c init.c inputs.c
SRCD   = srcs/
OBJD   = objs/
LIBD   = libs
LIBFT  = $(LIBD)/libft
BREWL  = $(HOME)/.brew/lib
BREWI  = $(HOME)/.brew/include
LIBS   = -L$(LIBFT) -lft -L$(BREWL) -lGLEW -lglfw.3
SRCS   = $(addprefix $(SRCD),$(FILES))
OBJS   = $(addprefix $(OBJD),$(FILES:.c=.o))
HEAD   = includes/viewer.h
INC    = -I$(LIBFT) -Iincludes -I$(BREWI)
CC     = gcc

.PHONY: lib all clean re fclean libft

all : $(NAME)

symlinks:
	rm -f libs
	ln -s ~/Documents/42projects/libs

libft:
	make -C $(LIBFT)

update:
	@echo "checking related repositories :"
	@printf "==> libft : "
	@git -C libs/libft pull
	@echo "done !"

build: libft

libs : update build

dir: build
	mkdir -p objs

$(OBJS): $(OBJD)%.o: $(SRCD)%.c ${HEAD}
	$(CC) $(CFLG) $(INC) -c -o $@ $<

$(NAME): dir $(OBJS)
	$(CC) $(LIBS) $(CFLG) -o $(BIN)/$@ $(OBJS) $(FRAMEWORKS)

clean:
		@rm -f $(OBJS)
		@echo "Objects cleaned."

fclean: clean
		@rm -f $(NAME)
		@echo "Binaries cleaned."

re: fclean all

relibs:
	make -C $(LIBFT) re

rebuild: fclean relibs all
