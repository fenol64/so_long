/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:30:33 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 19:02:17 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		close_hook(game);
		return (0);
	}
	game->move_count++;
	if (keycode == KEY_W || keycode == KEY_UP)
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
