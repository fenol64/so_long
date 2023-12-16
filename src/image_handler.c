/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:39 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 21:49:17 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	load_image(t_game *game, void **img_ptr, char *path)
{
	int	w;
	int	h;

	if (img_ptr)
		*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
}

void	put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img_ptr, x * BLOCK_SIZE, y * BLOCK_SIZE);
}

int	load_images(t_game *game)
{
	load_image(game, &game->floor_img, "src/assets/floor.xpm");
	load_image(game, &game->wall_img, "src/assets/wall.xpm");
	load_image(game, &game->collectible.img, "src/assets/collectible.xpm");
	load_image(game, &game->player.img_up, "src/assets/player-left.xpm");
	load_image(game, &game->player.img_left, "src/assets/player-left.xpm");
	load_image(game, &game->player.img_right, "src/assets/player-right.xpm");
	load_image(game, &game->player.img_up, "src/assets/player-up.xpm");
	load_image(game, &game->player.img_down, "src/assets/player-down.xpm");
	load_image(game, &game->exit.img, "src/assets/door.xpm");
	return (1);
}
