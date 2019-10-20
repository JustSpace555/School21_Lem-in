/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:49:53 by rsumner           #+#    #+#             */
/*   Updated: 2019/10/20 16:25:10 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_return_param(void)
{
	ft_printf("Invalid parameters, use -help for more information\n");
	return (ERR);
}

int	ft_get_param_4(t_param *p, t_sum *s)
{
	if (p->output_file != NULL)
		s->fd_write = open(p->output_file, O_WRONLY | O_CREAT | O_TRUNC,\
		S_IRUSR | S_IWUSR);
	if (p->input_file != NULL)
		s->fd_read = open(p->input_file, O_RDONLY);
	if ((s->fd_read < 0 || s->fd_write < 0) || (s->fd_write != 1 &&\
	((p->n_lines) || (p->comments) || (p->rooms) || (p->result))))
		return (ft_return_param());
	return (OK);
}

int	ft_get_param_2(int ac, char *str, t_param *p)
{
	if (ft_strcmp(str, "-help") == 0)
	{
		if (ac == 2)
			p->help = 1;
		else
			return (ERR);
	}
	else if (p->n_lines == 0 && ft_strcmp(str, "-lines") == 0)
		p->n_lines = 1;
	else if (p->comments == 0 && ft_strcmp(str, "-comments") == 0)
		p->comments = 1;
	else if (p->rooms == 0 && ft_strcmp(str, "-rooms") == 0)
		p->rooms = 1;
	else if (p->result == 0 && ft_strcmp(str, "-result") == 0)
		p->result = 1;
	else
		return (OK);
	return (STOP);
}

int	ft_get_param_3(char **av, int i, t_param *p)
{
	if (!(p->input_file) && ft_strcmp(av[i], "-in_file") == 0)
	{
		if (av[i + 1] != NULL)
			p->input_file = av[i + 1];
		else
			return (ERR);
	}
	else if (!(p->output_file) && ft_strcmp(av[i], "-out_file") == 0)
	{
		if (av[i + 1] != NULL)
			p->output_file = av[i + 1];
		else
			return (ERR);
	}
	else
		return (ERR);
	return (OK);
}

int	ft_get_param(int ac, char **av, t_param *p, t_sum *s)
{
	int i;
	int type;

	i = 0;
	while (++i < ac)
	{
		if ((type = ft_get_param_2(ac, av[i], p)) == ERR)
			return (ft_return_param());
		if (type != STOP)
		{
			if ((type = ft_get_param_3(av, i, p)) == ERR)
				return (ft_return_param());
			else
				i = i + 1;
		}
	}
	return (ft_get_param_4(p, s));
}
