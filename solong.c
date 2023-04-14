/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:04 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/13 22:14:04 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

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
    set_img(&game);
    game.win = mlx_new_window(game.mlx, game.map_height, game.map_width, "So_long");
    set_win(&game, game.map_width, game.map_height);
    mlx_loop(game.mlx);
    mlx_key_hook(game.win, key_hook, &game)
}