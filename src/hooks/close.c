/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:32:59 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/13 22:24:01 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void   free_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->floor_img);
    mlx_destroy_image(game->mlx, game->wall_img);
}

int	close_hook(t_game *game)
{
    free_images(game);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
