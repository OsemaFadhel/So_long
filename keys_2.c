/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:30:36 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/24 22:34:18 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	up_coin(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->player_y--;
	game->coin_count--;
}

void	down_coin(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->player_y++;
	game->coin_count--;
}

void	right_coin(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x + 1] = 'P';
	game->player_x++;
	game->coin_count--;
}

void	left_coin(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->player_x--;
	game->coin_count--;
}
