/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:27:38 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/27 15:36:43 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <sys/stat.h>
#include <fcntl.h>

int	add_data_2(char *str, t_sum *s, int type)
{
	char	**tab;
	int		stat;

	tab = NULL;
	if (type < 3)
	{
		stat = type;
		if (!(tab = ft_strsplit(str, ' ')))
			return (ft_clean_tab(ERR, tab));
		if ((type = add_room(s, tab, stat)) == ERR)
			return (ft_clean_tab(ERR, tab));
		ft_clean_tab(OK, tab);
	}
	if (type == 3)
	{
		if (!(tab = ft_strsplit(str, '-')))
			return (ft_clean_tab(ERR, tab));
		if ((type = add_link(s, tab)) == STOP || type == ERR)
			return (ft_clean_tab(type, tab));
		ft_clean_tab(OK, tab);
	}
	return (type);
}

int	add_data(char *str, t_sum *s, int type)
{
	if (str[0] == '#' && str[1] != '#')
		return (type = type > 1 ? type : 2);
	else if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
		{
			if (s->start < 0)
				type = 0;
			else
				type = STOP;
		}
		else if (ft_strcmp(str, "##end") == 0)
		{
			if (s->end < 0)
				type = 1;
			else
				type = STOP;
		}
		else
			return (type);
	}
	else
		return (add_data_2(str, s, type));
	return (type);
}

int	add_to_output(char **line, t_out **out)
{
	t_out *o;
	t_out *new;

	o = *out;
	if (!(new = (t_out *)malloc(sizeof(t_out))))
		return (ERR);
	new->text = *line;
	new->next = NULL;
	if (!*out)
		*out = new;
	else
	{
		while ((*out)->next)
			(*out) = (*out)->next;
		(*out)->next = new;
		*out = o;
	}
	return (OK);
}

int	ft_return_get(int stat, char **line)
{
	ft_strdel(line);
	get_next_line(-2, NULL);
	return (stat);
}

int	get_data(t_sum *s)
{
	int		r;
	char	*line;
	int		type;

	type = -1;
	line = NULL;
	while (s->n_ants == 0)
	{
		if (!(r = get_next_line(s->fd_read, &line)) || ft_strcmp(line,\
		"##start") == 0 || ft_strcmp(line, "##end") == 0)
			return (ft_return_get(ERR, &line));
		if ((line[0] != '#' && (get_nb(line, &(s->n_ants), 'a') == ERR || s->\
		n_ants <= 0)) || (((line[0] != '#' && s->n_ants > 0) || line[0] == '#')\
		&& add_to_output(&line, &(s->final_output)) == ERR))
			return (ft_return_get(ERR, &line));
		line = NULL;
	}
	while (type != STOP && (r = get_next_line(s->fd_read, &line)) && r != ERR)
	{
		if (((type = add_data(line, s, type)) == ERR) || (type != STOP &&\
		add_to_output(&line, &(s->final_output)) == ERR))
			return (ft_return_get(ERR, &line));
		type != STOP ? line = NULL : 0;
	}
	return (ft_return_get(OK, &line));
}
