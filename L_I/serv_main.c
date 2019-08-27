/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:48:39 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/22 17:30:44 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_clean_links(t_sum *s)
{
	t_link	*cur_l;
	t_link	*next_l;
	int		i;

	i = -1;
	while (++i < s->n_rooms)
	{
		cur_l = s->links[i];
		while (cur_l)
		{
			next_l = cur_l->next;
			free(cur_l);
			cur_l = next_l;
		}
	}
	free(s->links);
}

void		ft_clean_out(t_sum *s)
{
	t_out	*cur_o;
	t_out	*next_o;

	cur_o = s->final_output;
	while (cur_o)
	{
		next_o = cur_o->next;
		ft_strdel(&(cur_o->text));
		free(cur_o);
		cur_o = next_o;
	}
}

int			ft_return_main(int status, t_sum *s)
{
	t_room	*cur_r;
	t_room	*next_r;

	cur_r = s->room;
	while (cur_r)
	{
		next_r = cur_r->next;
		ft_strdel(&(cur_r->name));
		free(cur_r);
		cur_r = next_r;
	}
	if (s->links)
		ft_clean_links(s);
	ft_clean_out(s);
	if (status == ERR)
		write(1, "ERROR\n", 6);
	return (0);
}

t_sum		create_new_sum_structure(void)
{
	t_sum	s;

	s.room = NULL;
	s.links = NULL;
	s.n_ants = 0;
	s.n_rooms = 0;
	s.n_links = 0;
	s.start = -1;
	s.end = -1;
	s.final_output = NULL;
	s.dir = 0;
	s.fd_read = 0;
	s.fd_write = 1;
	return (s);
}

t_param		create_new_param_structute(void)
{
	t_param p;

	p.help = 0;
	p.input_file = NULL;
	p.output_file = NULL;
	p.n_lines = 0;
	p.comments = 0;
	p.rooms = 0;
	p.result = 0;
	return (p);
}
