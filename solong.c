/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/24 22:37:19 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_check	check;

	if (ac != 2)
	{
		printf("Error\nYou didn't put the map as an argument\n");
		return (1);
	}
	game.map = read_map(av[1], &game);
	check.map = read_map(av[1], &game);
	init(&game, &check);
	game.mlx = mlx_init();
	map_size(&game, &check);
	checks(&check, &game);
	game.win = mlx_new_window(game.mlx, game.map_width,
			game.map_height, "so_long");
	xpm_img(&game);
	set_win(&game);
	mlx_key_hook(game.win, key, &game);
	mlx_string_put(game.mlx, game.win, 1, 1, 12744232, itoa(game->move_count));
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
