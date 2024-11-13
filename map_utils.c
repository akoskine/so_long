/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:31:03 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:47 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_arg(t_game *game, int ac, char **av)
{
	if (ac < 2)
		exit_error("Too few arguments!\n", game);
	if (ac > 2)
		exit_error("Too many arguments!\n", game);
	if (!ft_strnstr(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
		exit_error("Wrong mapfile type!\n", game);
}

void	fill_map(t_game *game, int fd, int fd_2, int i)
{
	game->line = get_next_line(fd);
	if (game->line == NULL)
		exit_error("Empty file!\n", game);
	game->x = ft_strlen(game->line) - 1;
	free(game->line);
	if (game->x == 0)
		exit_error("First line empty!\n", game);
	while (game->line)
	{
		game->line = get_next_line(fd);
		free(game->line);
		game->y++;
	}
	game->map = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!game->map)
		exit_error("Memory allocation for map failed!\n", game);
	while (game->map)
	{
		game->map[i] = get_next_line(fd_2);
		if (!game->map[i])
			break ;
		i++;
	}
	game->map[i] = NULL;
}

void	remove_new_lines(t_game *game)
{
	int	i;

	i = game->y - 2;
	if (game->y > 1)
	{
		while (i >= 0)
		{
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
			i--;
		}
	}
}

void	test_flood(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	game->flood_map = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!game->flood_map)
		exit_error("Memory allocation for flood map failed!\n", game);
	while (j < game->y)
	{
		game->flood_map[j] = (char *)malloc(sizeof(char) * (game->x + 1));
		if (!game->flood_map[j])
			exit_error("Memory allocation for flood map failed!\n", game);
		while (game->map[j][i])
		{
			game->flood_map[j][i] = game->map[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	game->flood_map[j] = NULL;
	route_map(game, game->flood_map, game->p_x, game->p_y);
	free_map(game->flood_map);
}

void	create_map(t_game *game, int ac, char **av)
{
	int	fd;
	int	fd_2;
	int	i;

	i = 0;
	check_map_arg(game, ac, av);
	fd = open(av[1], O_RDONLY);
	fd_2 = open(av[1], O_RDONLY);
	if (fd == -1 || fd_2 == -1)
		exit_error("Mapfile not found!\n", NULL);
	fill_map(game, fd, fd_2, i);
	close(fd);
	close(fd_2);
	remove_new_lines(game);
	check_correct_size(game);
	check_outer_walls(game);
	check_required_objects(game);
	check_accepted_objects(game);
	find_player_exit(game);
	test_flood(game);
	if (game->e != 0 || game->p != 0 || game->c != game->req_c)
		exit_error("Map routing impossible!\n", game);
}
