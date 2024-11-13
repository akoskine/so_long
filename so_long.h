/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:19:34 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:57 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	char		**flood_map;
	char		*line;
	size_t		y;
	size_t		x;
	size_t		p;
	size_t		e;
	size_t		c;
	size_t		zero;
	size_t		req_c;
	size_t		p_y;
	size_t		p_x;
	size_t		e_y;
	size_t		e_x;
	size_t		close;
	int			counter;
}				t_game;

/* so_long */

void		init_struct(t_game *game);

/* utils.c */

void		exit_error(char *msg, t_game *game);
void		free_map(char **map);
int			press_x_icon(t_game *game);
void		find_player_exit(t_game *game);
void		show_moves(t_game *game);

/* map_utils */

void		check_map_arg(t_game *game, int ac, char **av);
void		fill_map(t_game *game, int fd, int fd_2, int i);
void		remove_new_lines(t_game *game);
void		test_flood(t_game *game);
void		create_map(t_game *game, int ac, char **av);

/* check_utils */

void		check_correct_size(t_game *game);
void		check_outer_walls(t_game *game);
void		check_required_objects(t_game *game);
void		check_accepted_objects(t_game *game);
void		route_map(t_game *game, char **flood_map, int x, int y);

/* configure_utils */

void		add_sprites(t_game *game);
void		draw_image(t_game *game, size_t image, size_t x, size_t y);
void		draw_exit(t_game *game);
void		draw_map(t_game *game);
void		configure_game(t_game *game);

/* move_utils */

int			move_event(int keycode, t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

#endif