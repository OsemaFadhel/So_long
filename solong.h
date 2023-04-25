/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:59:02 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/25 16:42:50 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <errno.h>
# include "printf/ft_printf.h"

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ESC 53

typedef struct s_check
{
	char	**map;
	int		map_height;
	int		map_width;
	int		player;
	int		exit;
	int		coin;
}				t_check;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		coin_count;
	int		moves;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*player;
	void	*enemy;
	void	*enemy_1;
	int		map_width;
	int		map_height;
	int		start;
	int		enemy_move;
	t_check	check;
}				t_game;

size_t	ft_strlen(const char *s);
int		count_words(char const *s, char c);
char	*strsub(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_len(long nb);
char	*ft_itoa(int n);

void	init(t_game *game, t_check *check);
char	**read_map(char *file, t_game *game);
void	map_size(t_game *game, t_check *check);
void	free_map(t_game *game);

void	set_win(t_game *game);
void	xpm_img(t_game *game);
void	put_img(t_game *game, int height, int width);
void	put_enemy(t_game *game, int height, int width);
void	put_exit(t_game *game, int height, int width);
int		close_game(t_game *game);

void	checks(t_check *check, t_game *game);
int		check_walls(t_check *check, int height, int width);
void	count_sprites(t_check *check, t_game *game, int height, int width);
void	check_map(t_check *check, t_game *game);
void	free_map_check(t_check *check);

int		key(int keycode, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
void	up_coin(t_game *game);
void	down_coin(t_game *game);
void	right_coin(t_game *game);
void	left_coin(t_game *game);

#endif
