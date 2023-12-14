/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:10:41 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/13 22:44:22 by fnascime         ###   ########.fr       */
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
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 16, y * 16);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * 16, y * 16);
        }
    }
}