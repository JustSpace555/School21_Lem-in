# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/09/18 19:06:37 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = add_room_link.c find_path.c get_data.c lists_moove.c lists.c main.c param.c print_result.c serv_get.c serv_main.c serv_solut.c solution.c
OBJ = add_room_link.o find_path.o get_data.o lists_moove.o lists.o main.o param.o print_result.o serv_get.o serv_main.o serv_solut.o solution.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo Compiling Lem_in ...
	@gcc $(FLAGS) $(SRC) -include ../libft/Headers/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)

new:
	@echo Recompiling Lem_in ...
	@rm -rf ../$(NAME)
	@gcc $(FLAGS) $(SRC) -include ../libft/Headers/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)

debug:
	@echo Recompiling Lem_in...
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM
	@gcc -g $(FLAGS) $(SRC) -include ../libft/Headers/libft.h -o $(NAME) ../libft.a
	@mv $(NAME) ../$(NAME)
	@mv $(NAME).dSYM ../$(NAME).dSYM

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM

re: fclean all
