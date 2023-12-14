/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:47:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/13 22:57:51 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_extension(char *map_path)
{
	if (ft_strnstr(map_path + ft_strlen(map_path) - 4, ".ber", 4))
		return (1);
	return (0);
}

static char	*get_map_str(char *map_path)
{
	int		fd;
	char	*ret;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ret = ft_strjoin_free_s1(ret, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (ret);
}

int *get_map_dimensions(char **map_str)
{
    int *dimensions;
    int i;
    int j;

    dimensions = malloc(sizeof(int) * 2);
    i = 0;
    j = 0;
    while (map_str[i])
    {
        j = 0;
        while (map_str[i][j])
        {
            j++;
        }
        i++;
    }
    dimensions[0] = j;
    dimensions[1] = i;
    return (dimensions);
}

int	check_map(char *map_path, t_game *game)
{
	char	*map_str;
    int     *dimensions;
	if (!(map_path && check_extension(map_path)))
		return (0);

	map_str = get_map_str(map_path);
	game->map = ft_split(map_str, '\n');
    dimensions = get_map_dimensions(game->map);
    game->map_width = dimensions[0] * 16;
    game->map_height = dimensions[1] * 16;
	game->player.amount = 0;
	game->collectible.amount = 0;
	game->exit.amount = 0;
    free(dimensions);
	free(map_str);
	return (1);
}
