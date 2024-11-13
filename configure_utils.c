/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:09:23 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:43 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_sprites(t_game *game)
{
	int	y;
	int	x;

	game->img = malloc(sizeof(void *) * 6);
	if (!game->img)
		exit_error("Memory allocation for sprites failed!\n", game);
	game->img[0] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/floor.xpm", &x, &y);
	game->img[1] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall.xpm", &x, &y);
	game->img[2] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/character.xpm", &x, &y);
	game->img[3] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/collect.xpm", &x, &y);
	game->img[4] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit.xpm", &x, &y);
	game->img[5] = mlx_xpm_file_to_image(game->mlx,
			"./sprites/open_exit.xpm", &x, &y);
}

void	draw_image(t_game *game, size_t image, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[image], x * 64, y * 64);
}

void	draw_exit(t_game *game)
{
	if (game->c == game->req_c)
		draw_image(game, 5, game->e_x, game->e_y);
	else
		draw_image(game, 4, game->e_x, game->e_y);
}

void	draw_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == '1')
				draw_image(game, 1, x, y);
			else if (game->map[y][x] == 'C')
				draw_image(game, 3, x, y);
			else if (game->map[y][x] == 'E')
				draw_image(game, 4, x, y);
			else
				draw_image(game, 0, x, y);
			x++;
		}
		y++;
	}
}

void	configure_game(t_game *game)
{
	game->mlx = mlx_init();
	add_sprites(game);
	game->win = mlx_new_window(game->mlx, game->x * 64,
			game->y * 64, "so_long");
	draw_map(game);
	draw_image(game, 2, game->p_x, game->p_y);
	game->c = 0;
	game->map[game->p_y][game->p_x] = '0';
	show_moves(game);
	mlx_hook(game->win, 17, 0, press_x_icon, game);
	mlx_hook(game->win, 2, 1L << 0, move_event, game);
	mlx_loop(game->mlx);
}
