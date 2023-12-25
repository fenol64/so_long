/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:01:03 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 02:55:51 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int    validade_extension(char *map_path)
{
	if (ft_strnstr(map_path + ft_strlen(map_path) - 4, ".ber", 4))
		return (1);
	return (0);
}

static void		validade_player_path(t_game *game, char **map, int x, int y)
{
	if (game->wall_error)
		return;
	if (map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		game->collectible.available++;
	if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E' ||
		map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
			game->exit.available = 1;
	map[y][x] = '1';

	if (map[y][x + 1] != '1')
		validade_player_path(game, map, x + 1, y);
	if (map[y][x - 1] != '1')
		validade_player_path(game, map, x - 1, y);
	if (map[y + 1][x] != '1')
		validade_player_path(game, map, x, y + 1);
	if (map[y - 1][x] != '1')
		validade_player_path(game, map, x, y - 1);
}

static void	validate_map_walls(char **map_str, int *wall_error)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_str[i])
	{
		j = 0;
		while (map_str[i][j])
		{
			if ((i == 0) || (i == ft_matrix_len(map_str) - 1))
			{
				if (map_str[i][j] != '1')
					*wall_error = 1;
			}
			else if ((j == 0) || (j == ft_strlen(map_str[i]) - 1))
			{
				if (map_str[i][j] != '1')
					*wall_error = 1;
			}
			j++;
		}
		i++;
	}
}

int	validate_map_entities(t_game *game)
{
	if (game->map_width == game->map_height)
		return (MAP_DIMENSION_ERROR);
	else if (game->wall_error)
		return (MAP_WALL_ERROR);
	else if (game->player.amount != 1)
		return (PLAYER_ERROR);
	else if (game->exit.amount != 1)
		return (EXIT_ERROR);
	else if (game->collectible.amount == 0)
		return (COLLECTABLE_ERROR);
	else if (game->collectible.available != game->collectible.amount)
		return (COLLECTABLE_ERROR);
	else if (game->exit.available != game->exit.amount)
		return (EXIT_ERROR);
	return (1);
}

int validate_map(char *map, t_game *game)
{
	char	**map_str;

	map_str = ft_split(map, '\n');
	if (!map_str)
		return (0);
	validate_map_walls(map_str, &game->wall_error);
	validade_player_path(game, map_str, game->player.x, game->player.y);
	ft_free_matrix(map_str);
	return (validate_map_entities(game));
}
