/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:14:21 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/22 19:42:31 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

    g = (t_game){0};
	if (argc != 2)
		ft_printf("Usage: ./so_long <map_path>.ber\n");
	else
	{
		if (!check_map(argv[1], &g))
			return (error());
		g.mlx = mlx_init();
		load_images(&g);
		g.win = mlx_new_window(g.mlx, g.map_width, g.map_height, "so_long");
		render_map(&g);
		mlx_key_hook(g.win, key_hook, &g);
		mlx_hook(g.win, 17, 0, close_hook, &g);
		mlx_loop(g.mlx);
	}
}
