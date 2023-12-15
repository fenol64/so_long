/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:14:21 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 01:57:32 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"


int    load_images(t_game *game)
{
    int w;
    int h;

    game->floor_img = mlx_xpm_file_to_image(game->mlx, "src/assets/floor.xpm", &w, &h);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "src/assets/wall.xpm", &w, &h);
    game->collectible.img = mlx_xpm_file_to_image(game->mlx, "src/assets/collectible.xpm", &w, &h);
    game->player.img = mlx_xpm_file_to_image(game->mlx, "src/assets/player.xpm", &w, &h);
    game->exit.img = mlx_xpm_file_to_image(game->mlx, "src/assets/door.xpm", &w, &h);
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
        load_images(&game);
        game.win = mlx_new_window(game.mlx, game.map_width, game.map_height, "so_long");
        render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, close_hook, &game);
		mlx_loop(game.mlx);
	}
}
