/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:02 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/20 20:37:24 by ofadhel          ###   ########.fr       */
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
# include <errno.h>

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ESC 53

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int     player_x;
    int     player_y;
	int		coin_count;
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
void	xpm_img(t_game *game);
void	put_img(t_game *game, int riga, int colonna);
void	set_win(t_game *game);
void	check_img(t_game *game);
void	set_exit(t_game *game, int height, int width);
void	set_eenem(t_game *game, int riga, int colonna);
void	free_map(t_game *game);
int     close_game(t_game *game);
void    map_size(t_game *game);

size_t	ft_strlen(const char *s);
int		count_words(char const *s, char c);
char	*strsub(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void    init(t_game *game);


int    	key(int keycode, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

#endif