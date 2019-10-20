/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:27:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/10/20 18:03:25 by qmebble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_print_help(void)
{
	ft_printf("%{yellow}s\n", "To managing input / output parameters");
	ft_printf("%{green}s  %{red}s: file with input data;\n", "in_file",\
	"[file_name]");
	ft_printf("%{green}s %{red}s: file for output data. Is сreated if it\
doesn't exist.\n", "out_file", "[file_name]");
	ft_printf("Incompatible with flags other than -in_file;\n\n");
	ft_printf("%{yellow}s\n", "To output selective parameters use:");
	ft_printf("%{green}s: print the comments on standart output;\n",\
	"-comments");
	ft_printf("%{green}s:    print number of rooms on standart output;\n",\
	"-rooms");
	ft_printf("%{green}s:    print number of lines in solution on standart\
 output;\n", "-lines");
	ft_printf("%{green}s:   print solution on standart output.\n", "-result");
	return (0);
}

int	main(int ac, char **av)
{
	t_sum	s;
	t_moove	*moove;
	t_queue *queue;
	t_param p;

	s = create_new_sum_structure();
	p = create_new_param_structute();
	if (ac > 1 && ft_get_param(ac, av, &p, &s) == ERR)
		return (ERR);
	if (p.help == 1)
		return (ft_print_help());
	if (read(s.fd_read, NULL, 0) < 0 || get_data(&s) == ERR || s.n_rooms < 2 ||\
	s.n_links < 1 || s.n_ants == 0\
	|| s.end == -1 || s.start == -1)
		return (ft_return_main(ERR, &s));
	if (find_solution(s, &moove, &queue) == ERR)
		return (ft_return_main(ERR, &s));
	print_result(&moove, &p, &s);
	ft_solut_return(OK, queue, moove, NULL);
	return (ft_return_main(OK, &s));
}
