/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:27:21 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/26 15:20:34 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*best_way(int step, int room, t_queue *q)
{
	t_queue *tmp;
	t_queue *best;
	int		best_step;

	tmp = q;
	best = q;
	best_step = tmp->step - tmp->stop;
	while (tmp && tmp->step == step)
	{
		if (tmp->room_nb == room && tmp->step - tmp->stop < best_step)
		{
			best_step = tmp->step - tmp->stop;
			best = tmp;
		}
		tmp = tmp->prev;
	}
	return (best);
}

int			fill_moove(int ant_num, t_queue *q, t_moove **moove)
{
	int	par;
	int	step;

	if (add_to_moove(ant_num, q, moove) == ERR)
		return (ERR);
	par = q->parent;
	step = q->step;
	while (q && q->step != 0)
	{
		if (q->room_nb == par && q->step == step - 1)
		{
			q = best_way(q->step, q->room_nb, q);
			if (add_to_moove(ant_num, q, moove) == ERR)
				return (ERR);
			par = q->parent;
			step = q->step;
		}
		q = q->prev;
	}
	return (OK);
}

int			find_path_2(t_sum *s, t_queue *queue, t_moove **m, char *tab)
{
	t_link	*l;
	t_queue	*q;
	int		free;
	int		status;

	q = queue;
	free = 0;
	status = OK;
	l = s->links[q->room_nb];
	while (l && status != ERR)
	{
		if (l->pair == s->end && (s->dir == 0 || (s->dir == 1 && q->room_nb !=\
		s->start) || (s->dir == 1 && q->room_nb == s->start && (free =\
		if_room_free(q->step + 1, l->pair, m)) == 0)))
			status = ft_add_q(l->pair, &q, tab);
		else if ((tab[l->pair] == 'a' && (free = if_room_free(q->step + 1, l->\
		pair, m)) == 0 && if_in_q(q->step + 1, q->room_nb, l->pair, &q) == 0))
			status = ft_add_q(l->pair, &q, tab);
		if (free == 1 && !if_in_q(q->step + 1, q->room_nb, q->room_nb, &q))
			status = ft_add_q(q->room_nb, &q, tab);
		l = l->next;
	}
	return (status);
}

t_queue		*best_solution(int step, int end, t_queue *queue)
{
	t_queue *tmp;
	t_queue *best;
	int		best_step;

	tmp = queue;
	best = queue;
	best_step = tmp->step - tmp->stop;
	while (tmp && tmp->step == step)
	{
		if (tmp->room_nb == end && tmp->step - tmp->stop < best_step)
		{
			best_step = tmp->step - tmp->stop;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}

int			find_path(int ant_num, t_sum *s, t_queue **q, t_moove **moove)
{
	t_queue *queue;
	t_queue *start_q;
	char	*tab;

	queue = *q;
	start_q = NULL;
	if ((tab = ft_create_mark(s->n_rooms)) == NULL ||\
	ft_add_q(s->start, &queue, tab) == ERR)
		return (ft_solut_return(ERR, start_q, *moove, tab));
	start_q = queue;
	while (queue && queue->room_nb != s->end)
	{
		if (find_path_2(s, queue, moove, tab) == ERR)
			return (ft_solut_return(ERR, start_q, *moove, tab));
		queue = queue->next;
	}
	if (!queue)
		return (ft_solut_return(ERR, start_q, *moove, tab));
	queue = best_solution(queue->step, s->end, queue);
	if (fill_moove(ant_num, queue, moove) == ERR)
		return (ft_solut_return(ERR, start_q, *moove, tab));
	*q = start_q;
	free(tab);
	return (OK);
}
