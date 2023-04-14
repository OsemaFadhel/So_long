/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:24:10 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/13 16:41:39 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

