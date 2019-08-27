/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:01:24 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/26 16:11:27 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define BUFF 5000
# define OK 0
# define ERR -1
# define STOP -2

typedef struct			s_room
{
	char				*name;
	int					n;
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	int					pair;
	int					mark;
	struct s_link		*next;
}						t_link;

typedef struct			s_out
{
	char				*text;
	struct s_out		*next;
}						t_out;

typedef struct			s_param
{
	int					help;
	char				*input_file;
	char				*output_file;
	int					n_lines;
	int					comments;
	int					rooms;
	int					result;
}						t_param;

typedef struct			s_sum
{
	int					n_ants;
	int					n_rooms;
	int					n_links;
	int					start;
	int					end;
	int					dir;
	int					fd_read;
	int					fd_write;
	t_room				*room;
	t_link				**links;
	t_out				*final_output;
}						t_sum;

typedef struct			s_ants
{
	int					ant_num;
	int					room;
	int					print;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_moove
{
	int					step_n;
	t_ants				*ants;
	struct s_moove		*next;
}						t_moove;

typedef struct			s_queue
{
	int					room_nb;
	int					step;
	int					stop;
	int					parent;
	struct s_queue		*prev;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_print
{
	char				buff[BUFF];
	int					len;
}						t_print;

int						get_data(t_sum *s);
int						add_room_list(t_room **room);
int						add_link_list(t_link **link);
int						ft_clean_tab(int stat, char **tab);
int						get_nb(char *str, int *nb, int type);
int						find_name_num(char *str, t_room *r);
char					**ft_split(char *s, char c);
int						find_solution(t_sum s, t_moove	**moove,\
						t_queue **queue);
void					print_result(t_moove **moove, t_param *p, t_sum *s);
int						if_room_checked(t_link	*links);
int						if_room_free(int step, int room, t_moove **moove);
int						if_in_q(int step, int parent,\
						int room_nb, t_queue **queue);
int						find_path(int ant_num, t_sum *s,\
						t_queue **q, t_moove **moove);
int						check_for_same_coor(t_sum *s);
int						ft_add_q(int room_nb, t_queue **queue, char *tab);
int						add_to_moove(int ant_num, t_queue *q, t_moove **moove);
t_sum					create_new_sum_structure(void);
int						ft_return_main(int status, t_sum *s);
void					ft_clean_out(t_sum *s);
void					ft_clean_links(t_sum *s);
int						add_link(t_sum *s, char **tab);
int						add_room(t_sum *s, char **tab, int stat);
int						ft_solut_return(int status, t_queue *queue,\
						t_moove *moove, char *tab);
void					ft_free_marks(int room_n, t_link **links);
t_param					create_new_param_structute(void);
int						ft_get_param(int ac, char **av, t_param *p, t_sum *s);
int						ft_print_help();
char					*ft_create_mark(int n);

#endif
