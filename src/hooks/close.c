/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:32:59 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 05:34:01 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->collectible.img);
	mlx_destroy_image(game->mlx, game->player.img_up);
	mlx_destroy_image(game->mlx, game->player.img_down);
	mlx_destroy_image(game->mlx, game->player.img_left);
	mlx_destroy_image(game->mlx, game->player.img_right);
	mlx_destroy_image(game->mlx, game->vilan.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->exit.frame_1);
	mlx_destroy_image(game->mlx, game->exit.frame_2);
	mlx_destroy_image(game->mlx, game->exit.frame_3);
	mlx_destroy_image(game->mlx, game->exit.frame_4);
	mlx_destroy_image(game->mlx, game->exit.frame_5);
	mlx_destroy_image(game->mlx, game->exit.frame_6);
	mlx_destroy_image(game->mlx, game->exit.frame_7);
	mlx_destroy_image(game->mlx, game->exit.frame_9);
	mlx_destroy_image(game->mlx, game->exit.frame_10);
}

void	free_minilibx(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_game(t_game *game, int freelib)
{
	ft_free_matrix(game->map);
	if (freelib)
		free_minilibx(game);
}

int	close_hook(t_game *game)
{
	free_game(game, 1);
	exit(0);
}
