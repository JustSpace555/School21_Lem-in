# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/10/20 16:56:48 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./libft/
	@make -C ./L_I/
	@make -C ./Vizualize/

new_lem_in:
	@make -C ./L_I/ new

new_Vizualize:
	@make -C ./Vizualize/ new

new: new_lem_in new_Vizualize

debug:
	@make -C ./L_I/ debug
	@make -C ./Vizualize/ debug

clean:
	@make -C ./L_I clean
	@make -C ./libft clean
	@make -C ./Vizualize/ clean

fclean: clean
	@make -C ./libft fclean
	@rm -rf libft.a
	@make -C ./L_I fclean
	@make -C ./Vizualize/ fclean

re: fclean all
