/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:50:24 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:49 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_event(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		game->close = 0;
		exit_error("GAME CLOSED\n", game);
	}
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	return (0);
}

void	move_up(t_game *game)
{
	if (game->map[game->p_y - 1][game->p_x] != '1')
	{
		if (game->map[game->p_y][game->p_x] == '0')
			draw_image(game, 0, game->p_x, game->p_y);
		else
			draw_exit(game);
		if (game->map[game->p_y - 1][game->p_x] == 'C')
		{
			draw_image(game, 0, game->p_x, game->p_y - 1);
			game->map[game->p_y - 1][game->p_x] = '0';
			game->c += 1;
			draw_exit(game);
		}
		draw_image(game, 2, game->p_x, game->p_y - 1);
		game->counter += 1;
		ft_printf("Move counter || %d\n", game->counter);
		show_moves(game);
		game->p_y -= 1;
		if (game->map[game->p_y][game->p_x] == 'E' && game->c == game->req_c)
		{
			game->close = 0;
			exit_error("Mission accomplished!\n", game);
		}
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->p_y + 1][game->p_x] != '1')
	{
		if (game->map[game->p_y][game->p_x] == '0')
			draw_image(game, 0, game->p_x, game->p_y);
		else
			draw_exit(game);
		if (game->map[game->p_y + 1][game->p_x] == 'C')
		{
			draw_image(game, 0, game->p_x, game->p_y + 1);
			game->map[game->p_y + 1][game->p_x] = '0';
			game->c += 1;
			draw_exit(game);
		}
		draw_image(game, 2, game->p_x, game->p_y + 1);
		game->counter += 1;
		ft_printf("Move counter || %d\n", game->counter);
		show_moves(game);
		game->p_y += 1;
		if (game->map[game->p_y][game->p_x] == 'E' && game->c == game->req_c)
		{
			game->close = 0;
			exit_error("Mission accomplished!\n", game);
		}
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->p_y][game->p_x - 1] != '1')
	{
		if (game->map[game->p_y][game->p_x] == '0')
			draw_image(game, 0, game->p_x, game->p_y);
		else
			draw_exit(game);
		if (game->map[game->p_y][game->p_x - 1] == 'C')
		{
			draw_image(game, 0, game->p_x - 1, game->p_y);
			game->map[game->p_y][game->p_x - 1] = '0';
			game->c += 1;
			draw_exit(game);
		}
		draw_image(game, 2, game->p_x - 1, game->p_y);
		game->counter += 1;
		ft_printf("Move counter || %d\n", game->counter);
		show_moves(game);
		game->p_x -= 1;
		if (game->map[game->p_y][game->p_x] == 'E' && game->c == game->req_c)
		{
			game->close = 0;
			exit_error("Mission accomplished!\n", game);
		}
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->p_y][game->p_x + 1] != '1')
	{
		if (game->map[game->p_y][game->p_x] == '0')
			draw_image(game, 0, game->p_x, game->p_y);
		else
			draw_exit(game);
		if (game->map[game->p_y][game->p_x + 1] == 'C')
		{
			draw_image(game, 0, game->p_x + 1, game->p_y);
			game->map[game->p_y][game->p_x + 1] = '0';
			game->c += 1;
			draw_exit(game);
		}
		draw_image(game, 2, game->p_x + 1, game->p_y);
		game->counter += 1;
		ft_printf("Move counter || %d\n", game->counter);
		show_moves(game);
		game->p_x += 1;
		if (game->map[game->p_y][game->p_x] == 'E' && game->c == game->req_c)
		{
			game->close = 0;
			exit_error("Mission accomplished!\n", game);
		}
	}
}
