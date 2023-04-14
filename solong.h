/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:02 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/13 16:40:15 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "get_next_line_bonus.h"
# include <errno.h>

# define TILE_WIDTH 64

# define WALL "img/wall.xpm"
# define FLOOR "img/floor.xpm"
# define COIN "img/coin.xpm"
# define PLAYER "img/player.xpm"
# define EXIT "img/exit.xpm"

# define UP 126;
# define DOWN 125;
# define LEFT 123;
# define RIGHT 124;

# define ESC = 53;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int     player_x;
    int     player_y;
	int		moves;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*player;
	int		map_width;
	int		map_height;
	int		start;
}               t_game;

char    **read_map(char *file, t_game *game);
void	set_img(t_game *game);
void	set_win(t_game *game, int riga, int colonna);
void	check_img(t_game *game);
void	set_eenem(t_game *game, int riga, int colonna);
void	free_map(t_game *game);


#endif