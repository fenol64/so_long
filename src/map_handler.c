/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:47:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/22 19:45:56 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*get_map_str(char *map_path)
{
	int		fd;
	char	*ret;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	ret = ft_strdup("");
	while (line)
	{
		ret = ft_strjoin_free_s1(ret, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (ret);
}

void	get_map_dimensions(char **map_str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map_str[++i])
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
	get_map_dimensions(game->map, game);
	if (!validate_map(map_str, game))
	{
		close_hook(game);
		return (0);
	}
	free(map_str);
	return (1);
}
