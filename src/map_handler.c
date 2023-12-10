/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:47:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/10 07:57:21 by fnascime         ###   ########.fr       */
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

int	check_map(char *map_path, t_game *game)
{
	char	*map_str;
	if (!(map_path && check_extension(map_path)))
		return (0);

	map_str = get_map_str(map_path);
	game->map = ft_split(map_str, '\n');
	game->map_width = 0;
	game->map_height = 0;
	game->player.amount = 0;
	game->collectible.amount = 0;
	game->exit.amount = 0;
	free(map_str);
	return (1);
}
