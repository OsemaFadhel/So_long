/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/14 18:39:03 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
    t_game	game;
    
    if (ac != 2)
	{
		printf("Error\nYou didn't put he map as an argument\n");
		return(1);
	}
    game.map = read_map(av[1], &game);
    game.mlx = mlx_init();
    map_size(&game);
    game.win = mlx_new_window(game.mlx, game.map_height, game.map_width, "So_long");
    set_img(&game);
    set_win(&game, game.map_height, game.map_width);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop(game.mlx);
}