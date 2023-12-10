/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:32:59 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/10 05:18:11 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_hook(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free(game);
	exit(0);
}
