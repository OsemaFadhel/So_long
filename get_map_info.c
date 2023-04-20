/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:24:10 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/20 20:38:27 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game);
	exit(1);
}

void    init(t_game *game)
{
	game->moves = 0;
	//game->no_collect = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coin_count = 0;
	game->start = 0;
	//game->enemy.mv = 0;
	//game->enemy_num = 0;
	//game->panel.strcd = 0;
	game->coin = 0;
	game->floor = 0;
	game->exit = 0;
	game->player = 0;
    game->map_width = 0;
    game->map_height = 0;
	//game->enemy.x = 0;
	//game->enemy.y = 0;
	//game->enemy_frame = 1;
}

void    map_size(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (game->map[i])
    {
        i++;
    }
    while (game->map[0][j])
    {   
        j++;
    }
    game->map_width = j * 64;
    game->map_height = i * 64;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

