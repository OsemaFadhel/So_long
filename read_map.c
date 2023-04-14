/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:08:19 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/13 16:43:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
	{
		return (NULL);
	}
	str = ft_memcpy(str, s, len);
	return (str);
}

char    **read_map(char *file, t_game *game)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (NULL);
    i = 0;
    while (get_next_line(fd) > 0)
    {
        line = get_next_line(fd);
        game->map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    game->map[i] = NULL;
    return (game->map);
}