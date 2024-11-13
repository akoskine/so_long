/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:04:42 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:40 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_correct_size(t_game *game)
{
	size_t	i;

	i = 0;
	if (game->y < 3)
		exit_error("Map height too small!\n", game);
	if (game->x < 3)
		exit_error("Map width too small!\n", game);
	if (game->map[game->y - 1][ft_strlen(game->map[game->y - 1]) - 1] == '\n')
		exit_error("Empty line in map!\n", game);
	while (game->map[i])
	{
		if (!ft_strlen(game->map[i]))
			exit_error("Empty line in map!\n", game);
		if ((ft_strlen(game->map[i])) != game->x)
			exit_error("Lines not equal length!\n", game);
		i++;
	}
}

void	check_outer_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->x)
	{
		if (game->map[0][i] != '1' || game->map[game->y - 1][i] != '1')
			exit_error("Outer walls not correct!\n", game);
		i++;
	}
	j = 1;
	while (j < game->y - 1)
	{
		if (game->map[j][0] != '1' || game->map[j][game->x - 1] != '1')
			exit_error("Outer walls not correct!\n", game);
		j++;
	}
}

void	check_required_objects(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while (j < game->y - 1)
	{
		while (i < game->x - 1)
		{
			if (game->map[j][i] == 'P')
				game->p += 1;
			else if (game->map[j][i] == 'E')
				game->e += 1;
			else if (game->map[j][i] == '0')
				game->zero += 1;
			else if (game->map[j][i] == 'C')
				game->c += 1;
			i++;
		}
		i = 1;
		j++;
	}
	if (game->p != 1 || game->e != 1 || game->c == 0 || game->zero == 0)
		exit_error("Wrong amount of required objects!\n", game);
}

void	check_accepted_objects(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while (j < game->y - 1)
	{
		while (i < game->x - 1)
		{
			if (game->map[j][i] != 'P' && game->map[j][i] != 'E'
				&& game->map[j][i] != 'C' && game->map[j][i] != '1'
				&& game->map[j][i] != '0')
				exit_error("Unacceptable objects in map!\n", game);
			i++;
		}
		i = 1;
		j++;
	}
}

void	route_map(t_game *game, char **flood_map, int x, int y)
{
	if (flood_map[y][x] == 'P')
		game->p = 0;
	else if (flood_map[y][x] == 'E')
		game->e = 0;
	else if (flood_map[y][x] == 'C')
		game->req_c += 1;
	flood_map[y][x] = 'X';
	if (flood_map[y][x - 1] != '1' && flood_map[y][x - 1] != 'X')
		route_map(game, flood_map, x - 1, y);
	if (flood_map[y + 1][x] != '1' && flood_map[y + 1][x] != 'X')
		route_map(game, flood_map, x, y + 1);
	if (flood_map[y - 1][x] != '1' && flood_map[y - 1][x] != 'X')
		route_map(game, flood_map, x, y - 1);
	if (flood_map[y][x + 1] != '1' && flood_map[y][x + 1] != 'X')
		route_map(game, flood_map, x + 1, y);
	else
		flood_map[y][x] = 'X';
}
