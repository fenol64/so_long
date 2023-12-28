/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:47:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/28 01:30:12 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*get_map_str(char *map_path)
{
	int		fd;
	char	*ret;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		ret = ft_strjoin_free(ret, line, 3);
		line = get_next_line(fd);
	}
	close(fd);
	return (ret);
}

int	check_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else if (BONUS_ENABLED && c == 'V')
		return (1);
	return (0);
}

int	check_map_chars(char *map_str)
{
	int	i;

	i = -1;
	while (map_str[++i])
	{
		if (!check_map_char(map_str[i]) && map_str[i] != '\n')
		{
			map_error(MAP_CHAR_ERROR);
			return (MAP_CHAR_ERROR);
		}
	}
	return (1);
}

void	get_map_dimensions(char **map_str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map_str[++i])
	{
		j = -1;
		while (map_str[i][++j])
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
		}
	}
	game->map_width = j * BLOCK_SIZE;
	game->map_height = i * BLOCK_SIZE;
}

int	check_map(char *map_path, t_game *game)
{
	char	*map_str;
	int		err_code;

	if (!(map_path && validade_extension(map_path)))
		return (0);
	map_str = get_map_str(map_path);
	if (!map_str || !*map_str || ft_strlen(map_str) == 0)
	{
		map_error(MAP_ERROR);
		free(map_str);
		return (0);
	}
	game->map = ft_split(map_str, '\n');
	get_map_dimensions(game->map, game);
	err_code = validate_map(map_str, game);
	if ((check_map_chars(map_str) < 0) || (err_code < 0))
	{
		map_error(err_code);
		free_game(game, 0);
		free(map_str);
		return (0);
	}
	free(map_str);
	return (1);
}
