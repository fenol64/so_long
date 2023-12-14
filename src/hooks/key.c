/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:30:33 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/14 15:45:02 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.y -= 1;
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.x -= 1;
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		game->map[game->player.y][game->player.x] = '0';
		game->player.x += 1;
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_hook(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game);
	else
		ft_printf("Invalid key\n");
	return (0);
}
