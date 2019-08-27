/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:44:32 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/26 16:37:49 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_init(int type, t_sum *s)
{
	t_out	*o;

	o = s->final_output;
	if (type == 2)
		ft_fprintf(1, "%{green}s\n", "Comments: ");
	while (o)
	{
		if (type == 1)
			ft_fprintf(s->fd_write, "%s\n", o->text);
		if (type == 2 && o->text && o->text[0] == '#' && o->text[1] != '#')
			ft_fprintf(1, "%s\n", o->text);
		o = o->next;
	}
}

void	print_solut(t_moove **moove, t_sum *s)
{
	t_moove	*m;
	t_ants	*a;
	t_room	*r;

	m = *moove;
	while (m)
	{
		a = m->ants;
		while (a)
		{
			r = s->room;
			while (r && r->n != a->room)
				r = r->next;
			if (a->print == 1)
				ft_fprintf(s->fd_write, "L%d-%s", a->ant_num, r->name);
			if (a->print == 1 && a->next != NULL)
				ft_fprintf(s->fd_write, " ");
			a = a->next;
		}
		ft_fprintf(s->fd_write, "\n");
		m = m->next;
	}
}

int		ft_find_lines(t_moove **moove)
{
	t_moove	*m;

	m = *moove;
	while (m->next)
		m = m->next;
	return (m->step_n);
}

void	print_result(t_moove **moove, t_param *p, t_sum *s)
{
	if (!p->n_lines && !p->comments && !p->rooms && !p->result)
	{
		print_init(1, s);
		ft_fprintf(s->fd_write, "\n");
		print_solut(moove, s);
	}
	else
	{
		if (p->rooms == 1)
			ft_fprintf(1, "%{green}s\n%d\n", "Number of rooms: ", s->n_rooms);
		if (p->comments == 1)
			print_init(2, s);
		if (p->n_lines == 1)
			ft_fprintf(1, "%{green}s\n%d\n", "Number of lines in solution: ",
				ft_find_lines(moove));
		if (p->result == 1)
		{
			ft_fprintf(1, "%{purple}s\n", "Solution:");
			print_solut(moove, s);
		}
	}
	close(s->fd_read);
	close(s->fd_write);
}
