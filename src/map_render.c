/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:10:41 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/14 13:58:35 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	render_map(t_game *game)
{
	// int	x;
	int	y;
    int x;

    y = -1;
    x = -1;
    while (game->map[++y])
    {
        x = -1;
        while (game->map[y][++x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player.img, x * BLOCK_SIZE, y * BLOCK_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * BLOCK_SIZE, y * BLOCK_SIZE);
        }
    }
}