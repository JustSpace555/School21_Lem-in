/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_moove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:15:50 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/23 19:34:14 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_step(int step_n, t_moove *new, t_moove **moove)
{
	t_moove *tmp;
	t_moove *m;

	m = *moove;
	while (m)
	{
		if (m->next == NULL || (m->step_n < step_n && m->next->step_n > step_n))
		{
			tmp = m->next;
			m->next = new;
			new->next = tmp;
			break ;
		}
		m = m->next;
	}
}

t_moove	*add_step(int step_n, t_moove **moove)
{
	t_moove *new;
	t_moove *m;

	if (!(new = (t_moove*)malloc(sizeof(t_moove))))
		return (NULL);
	new->ants = NULL;
	new->step_n = step_n;
	new->next = NULL;
	m = *moove;
	if (!(*moove))
		*moove = new;
	else if (m->step_n > step_n)
	{
		new->next = m;
		*moove = new;
	}
	else
		fill_step(step_n, new, moove);
	return (new);
}

int		add_to_moove(int ant_num, t_queue *q, t_moove **moove)
{
	t_moove	*m;
	t_ants	*new;
	t_ants	*a;

	m = *moove;
	while (m && m->step_n != q->step)
		m = m->next;
	if (m == NULL && !(m = add_step(q->step, moove)))
		return (ERR);
	if (!(new = (t_ants*)malloc(sizeof(t_ants))))
		return (ERR);
	new->ant_num = ant_num;
	new->room = q->room_nb;
	new->print = q->room_nb == q->parent ? 0 : 1;
	new->next = NULL;
	a = m->ants;
	if (m->ants == NULL)
		m->ants = new;
	else
	{
		while (a->next)
			a = a->next;
		a->next = new;
	}
	return (OK);
}
