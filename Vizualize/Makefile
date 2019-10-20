# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/14 14:54:15 by qmebble           #+#    #+#              #
#    Updated: 2019/09/18 19:06:23 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		parse_turns.c \
		vis_help.c \
		push_to_render.c

SRC_L_I =	../L_I/get_data.c \
			../L_I/serv_get.c \
			../L_I/lists.c \
			../L_I/add_room_link.c \
			../L_I/serv_main.c
INCLUDE =	visualise.h \
			../libft/Headers/libft.h
FLAGS = -Wall -Wextra -Werror
NAME = visualisator
FRAMEWORKS =	-I/Library/Frameworks/SDL2.framework/Headers -F ~/Library/Frameworks -framework SDL2 \
				-I/Library/Frameworks/SDL2_image.framework/Headers -F ~/Library/Frameworks -framework SDL2_image \
				-I/Library/Frameworks/SDL2_ttf.framework/Headers -F ~/Library/Frameworks -framework SDL2_ttf

all: $(NAME)

$(NAME):
	@echo Compiling Visualisator ...
	@bash script.bash
	@gcc $(FLAGS) $(SRC) $(SRC_L_I) -I $(INCLUDE) $(FRAMEWORKS) ../libft.a
	@mv a.out ../$(NAME)

new:
	@echo Recompiling Visualisator ...
	@rm -rf ../$(NAME)
	@gcc $(FLAGS) $(SRC) $(SRC_L_I) -I $(INCLUDE) $(FRAMEWORKS) ../libft.a
	@mv a.out ../$(NAME)

debug:
	@echo Recompiling Visualisator ...
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM
	@gcc -g $(FLAGS) $(SRC) $(SRC_L_I) -I $(INCLUDE) $(FRAMEWORKS) ../libft.a
	@mv a.out ../$(NAME)
	@mv a.out.dSYM ../$(NAME).dSYM

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ../$(NAME)
	@rm -rf ../$(NAME).dSYM

re: fclean all
