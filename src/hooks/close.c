/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:32:59 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 18:16:31 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void   free_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->floor_img);
    mlx_destroy_image(game->mlx, game->wall_img);
    mlx_destroy_image(game->mlx, game->collectible.img);
    mlx_destroy_image(game->mlx, game->player.img);
    mlx_destroy_image(game->mlx, game->exit.img);
}

void    free_map(t_game *game)
{
    int i;

    i = -1;
    while (game->map[++i])
        free(game->map[i]);
    free(game->map);
}

int	close_hook(t_game *game)
{
    free_map(game);
    free_images(game);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
	exit(0);
}
