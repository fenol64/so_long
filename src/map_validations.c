/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:01:03 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/22 19:49:17 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int    check_extension(char *map_path)
{
    if (ft_strnstr(map_path + ft_strlen(map_path) - 4, ".ber", 4))
        return (1);
    return (0);
}

static void		check_map_chars(t_game *game, char **map, int x, int y)
{
    if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->collectible.available++;
    if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E' ||
		map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
        	game->exit.available++;
    map[y][x] = '1';

    if (map[y][x + 1] != '1')
        check_map_chars(game, map, x + 1, y);
    if (map[y][x - 1] != '1')
        check_map_chars(game, map, x - 1, y);
    if (map[y + 1][x] != '1')
        check_map_chars(game, map, x, y + 1);
    if (map[y - 1][x] != '1')
        check_map_chars(game, map, x, y - 1);
}

int	validate_map_entities(t_game *game)
{
	if (game->map_width == game->map_height)
		return (0);
	if (game->player.amount != 1 || game->exit.amount != 1)
		return (0);
	if (game->collectible.amount == 0
		|| game->collectible.amount != game->collectible.available)
		return (0);
	if (game->exit.amount == 0)
		return (0);
	return (1);
}

int validate_map(char *map, t_game *game)
{
	char	**map_str;

	map_str = ft_split(map, '\n');
	if (!map_str)
		return (0);
	check_map_chars(game, map_str, game->player.x, game->player.y);
	ft_free_matrix(map_str);
	if (!validate_map_entities(game) || (game->exit.available != 1))
		return (0);
	return (1);
}