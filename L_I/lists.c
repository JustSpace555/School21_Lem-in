/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:43:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/23 19:49:58 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_room_list(t_room **room)
{
	t_room	*tmp;
	t_room	*list;

	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		return (ERR);
	ft_bzero(tmp, sizeof(t_room));
	tmp->next = NULL;
	list = *room;
	tmp->next = list;
	*room = tmp;
	return (OK);
}

int		add_link_list(t_link **link)
{
	t_link	*tmp;
	t_link	*list;

	tmp = NULL;
	if (!(tmp = (t_link*)malloc(sizeof(t_link))))
		return (ERR);
	tmp->next = NULL;
	list = *link;
	tmp->next = list;
	*link = tmp;
	return (OK);
}

void	fill_list(t_queue **new, int step, int parent, int room_nb)
{
	(*new)->room_nb = room_nb;
	(*new)->step = step;
	(*new)->parent = parent;
	(*new)->next = NULL;
	(*new)->prev = NULL;
}

int		ft_add_q(int room_nb, t_queue **queue, char *tab)
{
	t_queue *q;
	t_queue *new;
	int		step;
	int		parent;

	q = *queue;
	step = q == NULL ? 0 : (*queue)->step + 1;
	parent = q == NULL ? -1 : (*queue)->room_nb;
	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (ERR);
	fill_list(&new, step, parent, room_nb);
	new->stop = *queue == NULL ? 0 : q->stop;
	parent == room_nb ? new->stop++ : 0;
	if (*queue)
	{
		while ((*queue)->next)
			(*queue) = (*queue)->next;
		(*queue)->next = new;
		new->prev = (*queue);
		(*queue) = q;
	}
	else
		(*queue) = new;
	tab[room_nb] = 'b';
	return (OK);
}
