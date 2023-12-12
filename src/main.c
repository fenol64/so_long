/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:14:21 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/12 15:46:32 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


int    load_images(t_game *game)
{
    int w = 50;
    int h = 50;

    game->floor_img = mlx_xpm_file_to_image(game->mlx, "./assets/floor_1.xpm", &w, &h);
    ft_printf("w: %d\n", game->floor_img);
    if (!game->floor_img)
        ft_printf("Error to get image\n");
    if (!mlx_put_image_to_window(game->mlx, game->win, game->floor_img, w, h))
        ft_printf("Error to load image\n");
    return (1);
}

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

        if (load_images(&game) == 0)
            return (error());

		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, close_hook, &game);
		mlx_loop(game.mlx);
	}
}
