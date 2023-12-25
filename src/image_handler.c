/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:39 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 06:13:06 by fnascime         ###   ########.fr       */
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
	mlx_do_sync(game->mlx);
}

int	load_images(t_game *game)
{
	load_image(game, &game->floor_img, "src/assets/floor.xpm");
	load_image(game, &game->wall_img, "src/assets/wall.xpm");
	load_image(game, &game->collectible.img, "src/assets/collectible.xpm");
	load_image(game, &game->player.img_left, "src/assets/player-left.xpm");
	load_image(game, &game->player.img_right, "src/assets/player-right.xpm");
	load_image(game, &game->player.img_up, "src/assets/player-up.xpm");
	load_image(game, &game->player.img_down, "src/assets/player-down.xpm");
	load_image(game, &game->vilan.img, "src/assets/enimy.xpm");
	load_image(game, &game->exit.img, "src/assets/door_sprite/frame_0.xpm");
	load_image(game, &game->exit.frame_1, "src/assets/door_sprite/frame_1.xpm");
	load_image(game, &game->exit.frame_2, "src/assets/door_sprite/frame_2.xpm");
	load_image(game, &game->exit.frame_3, "src/assets/door_sprite/frame_3.xpm");
	load_image(game, &game->exit.frame_4, "src/assets/door_sprite/frame_4.xpm");
	load_image(game, &game->exit.frame_5, "src/assets/door_sprite/frame_5.xpm");
	load_image(game, &game->exit.frame_6, "src/assets/door_sprite/frame_6.xpm");
	load_image(game, &game->exit.frame_7, "src/assets/door_sprite/frame_7.xpm");
	load_image(game, &game->exit.frame_9, "src/assets/door_sprite/frame_9.xpm");
	load_image(game, &game->exit.frame_10, "src/assets/door_sprite/frame_10.xpm");
	return (1);
}
