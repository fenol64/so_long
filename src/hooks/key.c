/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:30:33 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/10 05:17:31 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_hook(game);
	else if (keycode == KEY_W)
		ft_printf("Move up\n");
	else if (keycode == KEY_A)
		ft_printf("Move left\n");
	else if (keycode == KEY_S)
		ft_printf("Move down\n");
	else if (keycode == KEY_D)
		ft_printf("Move right\n");
	else
		ft_printf("Invalid key\n");
	return (0);
}
