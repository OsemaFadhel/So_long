/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:35 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/20 20:37:57 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	xpm_img(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
			&game->map_width, &game->map_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->map_width, &game->map_height);
	//if (game->start == 0)
		game->player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
				&game->map_width, &game->map_height);
	/* if (game->coin > 0)
	{
		game->exit = mlx_xpm_file_to_image(game->mlx, "img/floor.xpm",
				&game->map_width, &game->map_height);
	} */ 
	/*if (game->coin == 0) */
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
				&game->map_width, &game->map_height); 
	game->coin = mlx_xpm_file_to_image(game->mlx,
			"img/coin.xpm", &game->map_width, &game->map_height);
	/*  game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy.xpm",
			&game->map_width, &game->map_height); */ 
}
void	put_img(t_game *game, int height, int width)
{
	if (game->map[height][width] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
					width * 64, height * 64);
	}
	if (game->map[height][width] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			width * 64, height * 64);
	}
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			width * 64, height * 64);
		game->player_x = width;
		game->player_y = height;
	}
	if (game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			width * 64, height * 64);
		game->coin_count++;
	}
	width++;
	if (game->map[height][width] == 'E')
		set_exit(game, height, width);
}

/* void	check_img(t_game *game)
{
	if (!game->floor || !game->wall || !game->player_x 
		|| !game->player_y || !game->exit || !game->coin)
	{
		printf("ERROR image\n");
	}
} */ 

void	set_exit(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->exit,
			width * 64, height * 64);
}

/*void	set_eenem(t_game *game, int height, int width)
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
	if (game->map[width]][height] == ENEMY_S)
	{
		game->enemy.x =[width];
		game->enemy.y = height;
		game->enemy_num++;
	} 
} */
void	set_win(t_game *game)
{
	int	height;
	int	width;

	// check_img(game);
	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			put_img(game, height, width);
			width++;
		}
		height++;
	}
}