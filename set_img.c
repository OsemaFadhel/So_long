/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:35 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/20 17:14:55 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	set_img(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
			&game->map_width, &game->map_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->map_width, &game->map_height);
	if (game->start == 0)
		game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
				&game->map_width, &game->map_height);
	/* if (game->coin > 0)
	{
		game->exit = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
				&game->map_width, &game->map_height);
	} */ 
	if (game->coin == 0)
		game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
				&game->map_width, &game->map_height);
	game->coin = mlx_xpm_file_to_image(game->mlx,
			"img/coin.xpm", &game->map_width, &game->map_height);
	/*  game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
			&game->map_width, &game->map_height); */ 
}
void	set_win(t_game *game, int height, int width)
{
	while (game->map[height])
	{
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					width, height);
			}
			if (game->map[height][width] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					width, height);
			}
			if (game->map[height][width] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->player,
					width, height);
				game->player_x = width;
				game->player_y = height;
			}
			if (game->map[height][width] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->coin,
					width, height);
			}
			width++;
		}
		height++;
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

void	set_eenem(t_game *game, int height, int width)
{
	if (game->map[height][width] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			width * 64, height * 64);
	}
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			width * 64, height * 64);
	}
	/*if (game->map[width]][height] == ENEMY_S)
	{
		game->enemy.x =[width];
		game->enemy.y = height;
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