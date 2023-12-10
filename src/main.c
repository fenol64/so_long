/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:14:21 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/10 07:57:50 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
    t_game	game;

	if (argc != 2)
		ft_printf("Usage: ./so_long <map_path>.ber\n");
	else
	{
		if (!check_map(argv[1], &game))
			return (error());

		game.mlx = mlx_init();
        game.win = mlx_new_window(game.mlx, 900, 500, "so long");

		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, close_hook, &game);
		mlx_loop(game.mlx);
	}
}
