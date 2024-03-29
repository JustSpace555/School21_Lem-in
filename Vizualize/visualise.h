#ifndef VISUALISE_H
# define VISUALISE_H

# include "SDL2.framework/Headers/SDL.h"
# include "SDL2_image.framework/Headers/SDL_image.h"
# include "SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../L_I/lem_in.h"
# include <stdio.h>
# include <stdbool.h>
# include <time.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SCREEN_FPS 60
# define SCREEN_TICKS_PER_FRAME 1000 / SCREEN_FPS

SDL_Window					*g_main_window;
SDL_Renderer				*g_main_render;
bool						g_debug;
t_sum						g_s;

typedef struct				s_vis_rooms
{
	SDL_FRect				room;
	struct s_vis_rooms		*next;
	char					*name;
	int						num;
	unsigned short int		r;
	unsigned short int		g;
	unsigned short int		b;
}							t_vis_rooms;

t_vis_rooms					*g_vis_rooms;

typedef struct				s_vis_ants
{
	char					*current_room_name;
	char					*next_room_name;
	SDL_FRect				current_room;
	SDL_FRect				next_room;
	float					x_diff;
	float					y_diff;
}							t_vis_ants;

typedef struct				s_turns_parser
{
	char					**ant_and_room;
	struct s_turns_parser	*next;
}							t_turns_parser;

bool						init(void);
t_vis_rooms					*push_rooms_to_render(t_sum s);
void						push_links_ro_render(t_sum s);
void						push_names_ro_render(t_sum s);
void						push_ant_texture_to_render(SDL_FRect pos);
t_vis_rooms					*make_new_vis_room();
int							ft_find_max_x(t_sum s);
int							ft_find_max_y(t_sum s);
int							close_all(void);

bool						parse_turns_line(t_vis_ants **array);
t_turns_parser				*make_new_ant_turn(void);
t_vis_ants					*make_new_vis_ants_array(t_sum s);

#endif
