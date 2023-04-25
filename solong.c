/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/25 16:52:32 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_map_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
	{
		ft_printf("Error: map name must be .ber\n");
		exit(1);
	}
}

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
		ft_printf("Error: no map\n");
		return (1);
	}
	check_map_name(av[1]);
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
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free(game.mlx);
	return (0);
}
