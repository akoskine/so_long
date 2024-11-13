/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoskine <akoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:24:36 by akoskine          #+#    #+#             */
/*   Updated: 2024/11/13 14:21:51 by akoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->img = NULL;
	game->map = NULL;
	game->flood_map = NULL;
	game->line = NULL;
	game->y = 0;
	game->x = 0;
	game->p = 0;
	game->e = 0;
	game->c = 0;
	game->zero = 0;
	game->req_c = 0;
	game->p_y = 0;
	game->p_x = 0;
	game->e_y = 0;
	game->e_x = 0;
	game->close = 1;
	game->counter = 0;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	init_struct(game);
	create_map(game, ac, av);
	configure_game(game);
	return (0);
}
