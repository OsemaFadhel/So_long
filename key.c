/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:56 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/24 22:33:40 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == UP)
		game->moves += move_up(game);
	if (keycode == DOWN)
		game->moves += move_down(game);
	if (keycode == LEFT)
		game->moves += move_left(game);
	if (keycode == RIGHT)
		game->moves += move_right(game);
	set_win(game);
	return (0);
}

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->player_y--;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		up_coin(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'E'
				&& game->coin_count == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		close_game(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'N')
	{
		printf("You lost!\n");
		close_game(game);
	}
	return (1);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->player_y++;
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		down_coin(game);
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'E'
				&& game->coin_count == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		close_game(game);
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'N')
	{
		printf("You lost!\n");
		close_game(game);
	}
	return (1);
}

int	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->player_x++;
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		right_coin(game);
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->coin_count == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		close_game(game);
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'N')
	{
		printf("You lost!\n");
		close_game(game);
	}
	return (1);
}

int	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->player_x--;
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		left_coin(game);
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'E'
				&& game->coin_count == 0)
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		close_game(game);
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'N')
	{
		printf("You lost!\n");
		close_game(game);
	}
	return (1);
}
