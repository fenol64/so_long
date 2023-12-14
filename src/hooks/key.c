/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:30:33 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/14 14:48:21 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_hook(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		ft_printf("Move up\n");
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_printf("Move left\n");
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_printf("Move down\n");
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_printf("Move right\n");
	else
		ft_printf("Invalid key\n");
	return (0);
}
