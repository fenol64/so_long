/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:10:28 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/15 02:37:25 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
        if (game->map[game->player.y - 1][game->player.x] == 'E'
            && game->collectible.amount != 0)
            return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.y -= 1;
        if (game->map[game->player.y][game->player.x] == 'C')
            game->collectible.amount--;
        else if (game->map[game->player.y][game->player.x] == 'E' && game->collectible.amount == 0)
            close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
        if (game->map[game->player.y + 1][game->player.x] == 'E'
            && game->collectible.amount != 0)
            return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
        if (game->map[game->player.y][game->player.x] == 'C')
            game->collectible.amount--;
        else if (game->map[game->player.y][game->player.x] == 'E' && game->collectible.amount == 0)
            close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player.y][game->player.x - 1] != '1')
    {
        if (game->map[game->player.y][game->player.x - 1] == 'E'
            && game->collectible.amount != 0)
            return ;
        game->map[game->player.y][game->player.x] = '0';
        game->player.x -= 1;
        if (game->map[game->player.y][game->player.x] == 'C')
            game->collectible.amount--;
        else if (game->map[game->player.y][game->player.x] == 'E' && game->collectible.amount == 0)
            close_hook(game);
        game->map[game->player.y][game->player.x] = 'P';
        render_map(game);
    }
}

void	move_right(t_game *game)
{
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
        if (game->map[game->player.y][game->player.x + 1] == 'E'
            && game->collectible.amount != 0)
            return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.x += 1;
        if (game->map[game->player.y][game->player.x] == 'C')
            game->collectible.amount--;
        else if (game->map[game->player.y][game->player.x] == 'E' && game->collectible.amount == 0)
            close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		render_map(game);
	}
}