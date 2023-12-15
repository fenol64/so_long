/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:47:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 02:12:51 by fnascime         ###   ########.fr       */
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

void    get_map_dimensions(char **map_str, t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map_str[i])
    {
        j = 0;
        while (map_str[i][j])
        {
            if (map_str[i][j] == 'P')
            {
                game->player.x = j;
                game->player.y = i;
                game->player.amount++;
            }
            else if (map_str[i][j] == 'C')
                game->collectible.amount++;
            else if (map_str[i][j] == 'E')
                game->exit.amount++;
            j++;
        }
        i++;
    }
    game->map_width = j * BLOCK_SIZE;
    game->map_height = i * BLOCK_SIZE;
}

int	check_map(char *map_path, t_game *game)
{
	char	*map_str;


	if (!(map_path && check_extension(map_path)))
		return (0);
	map_str = get_map_str(map_path);
	game->map = ft_split(map_str, '\n');
    game->move_count = 0;
	game->collectible.amount = 0;
	game->player.amount = 0;
	game->exit.amount = 0;
    get_map_dimensions(game->map, game);
	free(map_str);
	return (1);
}
