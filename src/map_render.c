/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:10:41 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 06:13:35 by fnascime         ###   ########.fr       */
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

void	render_player(t_game *game)
{
	if (game->player.direction == 'U')
		put_img(game, game->player.img_up, game->player.x, game->player.y);
	else if (game->player.direction == 'D')
		put_img(game, game->player.img_down, game->player.x, game->player.y);
	else if (game->player.direction == 'L')
		put_img(game, game->player.img_left, game->player.x, game->player.y);
	else
		put_img(game, game->player.img_right, game->player.x, game->player.y);
}

void render_door(t_game *game, int x, int y)
{
	if (game->collectible.amount == 0 && game->door_opened == 0)
	{
		put_img(game, game->exit.frame_1, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_2, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_3, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_4, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_5, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_6, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_7, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_9, x, y);
		ft_sleep(3);
		put_img(game, game->exit.frame_10, x, y);
		game->door_opened = 1;
	}
	else if (game->collectible.amount == 0 && game->door_opened == 1)
		put_img(game, game->exit.frame_10, x, y);
	else
		put_img(game, game->exit.img, x, y);
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
				render_player(game);
			else if (game->map[y][x] == 'E')
				render_door(game, x, y);
			else if (game->map[y][x] == 'V')
				put_img(game, game->vilan.img, x, y);
			else
				put_img(game, game->floor_img, x, y);
		}
	}
	render_map_texts(game);
}
