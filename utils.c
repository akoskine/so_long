/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:39:30 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:54 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg, t_game *game)
{
	int	close;

	close = 1;
	if (game != NULL && game->close == 0)
		close = 0;
	if (game != NULL)
	{
		if (game->img != NULL)
			free(game->img);
		free_map(game->map);
		free(game);
	}
	if (close == 0)
	{
		write(1, msg, ft_strlen(msg));
		exit(0);
	}
	else
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	press_x_icon(t_game *game)
{
	game->close = 0;
	exit_error("GAME CLOSED\n", game);
	return (0);
}

void	find_player_exit(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
			}
			if (game->map[y][x] == 'E')
			{
				game->e_y = y;
				game->e_x = x;
			}
			x++;
		}
		y++;
	}
}

void	show_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->counter);
	draw_image(game, 1, 0, 0);
	mlx_string_put(game->mlx, game->win, 8, 25, 0xffffff, "MOVES");
	mlx_string_put(game->mlx, game->win, 22, 40, 0xffffff, str);
	free(str);
}
