/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:35 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/13 22:14:04 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	set_img(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "FLOOR",
			&game->map_width, &game->map_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "WALL",
			&game->map_width, &game->map_height);
	if (game->start == 0)
		game->player = mlx_xpm_file_to_image(game->mlx, "PLAYER",
				&game->map_width, &game->map_height);
	if (game->coin > 0)
	{
		game->exit = mlx_xpm_file_to_image(game->mlx, "FLOOR",
				&game->map_width, &game->map_height);
	}
	if (game->coin == 0)
		game->exit = mlx_xpm_file_to_image(game->mlx, "EXIT",
				&game->map_width, &game->map_height);
	game->coin = mlx_xpm_file_to_image(game->mlx,
			"COIN", &game->map_width, &game->map_height);
	/*  game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
			&game->map_width, &game->map_height); */ 
}
void	set_win(t_game *game, int riga, int colonna)
{
	if (game->map[riga][colonna] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			colonna * 64, riga * 64);
	}
	if (game->map[riga][colonna] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			colonna * 64, riga * 64);
	}
	if (game->map[riga][colonna] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			colonna * 64, riga * 64);
		game->player_x = riga;
		game->player_y = colonna;
	}
	if (game->map[riga][colonna] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			colonna * 64, riga * 64);
	}
}

void	check_img(t_game *game)
{
	set_img(game);
	if (!game->floor|| !game->wall || !game->player_x 
		|| !game->player_y || !game->exit || !game->coin)
	{
		printf("error image wasn't read correctly\n");
	}
	game->start = 1;
}

void	set_eenem(t_game *game, int riga, int colonna)
{
	if (game->map[riga][colonna] == game.exit)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			colonna * 64, riga * 64);
	}
	/*if (game->map[riga][colonna] == ENEMY_S)
	{
		game->enemy.x = riga;
		game->enemy.y = colonna;
		game->enemy_num++;
	} */
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