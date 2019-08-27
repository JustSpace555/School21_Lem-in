/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:30:42 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/20 11:42:51 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	add_room(t_sum *s, char **tab, int stat)
{
	int x;
	int y;

	if (!tab || !*tab)
		return (ERR);
	if ((tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL)\
	&& tab[0][0] != 'L')
		return (3);
	if (tab[0][0] == 'L' || get_nb(tab[1], &x, 'r') == ERR ||\
	get_nb(tab[2], &y, 'r') == ERR || find_name_num(tab[0], s->room) != ERR ||\
	add_room_list(&(s->room)) == ERR)
		return (ERR);
	if (!(s->room->name = ft_strdup(tab[0])))
		return (ERR);
	s->room->n = s->room->next == NULL ? 0 : s->room->next->n + 1;
	s->room->x = x;
	s->room->y = y;
	s->n_rooms++;
	if (check_for_same_coor(s) == ERR)
		return (ERR);
	if ((stat == 0 && s->start != -1) || (stat == 1 && s->end != -1))
		return (ERR);
	stat == 0 ? s->start = s->room->n : 0;
	stat == 1 ? s->end = s->room->n : 0;
	return (2);
}

int	fill_link(t_sum *s, int n_a, int n_b)
{
	t_link *tmp;

	tmp = s->links[n_a];
	while (tmp)
	{
		if (tmp->pair == n_b)
			return (STOP);
		tmp = tmp->next;
	}
	if (add_link_list(&(s->links[n_a])) == ERR ||\
	add_link_list(&(s->links[n_b])) == ERR)
		return (ERR);
	s->links[n_a]->pair = n_b;
	s->links[n_b]->pair = n_a;
	s->n_links++;
	if ((n_a == s->start && n_b == s->end) ||\
	(n_b == s->start && n_a == s->end))
		s->dir = 1;
	return (OK);
}

int	add_link(t_sum *s, char **tab)
{
	int n_a;
	int n_b;
	int stat;

	if (!s->links)
	{
		if (!(s->links = (t_link **)malloc(sizeof(t_link *) * s->n_rooms)))
			return (ERR);
		ft_bzero(s->links, sizeof(t_link *) * s->n_rooms);
	}
	if (tab[0] == NULL || tab[1] == NULL || tab[2] != NULL)
		return (STOP);
	if ((n_a = find_name_num(tab[0], s->room)) == -1 ||\
	(n_b = find_name_num(tab[1], s->room)) == -1 || n_a == n_b)
		return (STOP);
	if ((stat = fill_link(s, n_a, n_b)) == ERR || stat == STOP)
		return (stat);
	return (3);
}
