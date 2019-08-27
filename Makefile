# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 11:06:11 by rsumner           #+#    #+#              #
#    Updated: 2019/08/19 18:13:03 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./libft/
	@make -C ./L_I/
	@make -C ./Visualise/

new_lem_in:
	@make -C ./L_I/ new

new_visualise:
	@make -C ./Visualise/ new

new: new_lem_in new_visualise

debug:
	@make -C ./L_I/ debug
	@make -C ./Visualise/ debug

clean:
	@make -C ./L_I clean
	@make -C ./libft clean
	@make -C ./Visualise/ clean

fclean: clean
	@make -C ./libft fclean
	@rm -rf libft.a
	@make -C ./L_I fclean
	@make -C ./Visualise/ fclean

re: fclean all
