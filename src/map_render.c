/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:10:41 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 20:42:15 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	render_map_texts(t_game *game)
{
	char	*str;
	char	*number;

	number = ft_itoa(game->move_count);
	str = ft_strjoin("Moves: ", number);
	mlx_string_put(game->mlx, game->win, 18, 18, 0x00FFFFFF, str);
	free(str);
	free(number);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				put_img(game, game->wall_img, x, y);
			else if (game->map[y][x] == 'C')
				put_img(game, game->collectible.img, x, y);
			else if (game->map[y][x] == 'P')
				put_img(game, game->player.img, x, y);
			else if (game->map[y][x] == 'E')
				put_img(game, game->exit.img, x, y);
			else
				put_img(game, game->floor_img, x, y);
		}
	}
	render_map_texts(game);
}
