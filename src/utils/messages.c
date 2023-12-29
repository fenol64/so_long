/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 04:56:55 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/29 12:56:49 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

void	map_error(int error_code)
{
    error();
	if (error_code == BER_ERROR)
		ft_putendl_fd("O mapa precisa ter o formato.ber", 2);
	else if (error_code == MAP_DIMENSION_ERROR)
		ft_putendl_fd("O mapa precisa ser retangular", 2);
	else if (error_code == PLAYER_ERROR)
		ft_putendl_fd("O mapa precisa ter um jogador", 2);
	else if (error_code == EXIT_ERROR)
		ft_putendl_fd("O mapa precisa ter uma saida", 2);
	else if (error_code == COLLECTABLE_ERROR)
		ft_putendl_fd("O mapa precisa ter ao menos uma coletavel", 2);
	else if (error_code == MAP_ERROR)
		ft_putendl_fd("O mapa não foi construido corretamente", 2);
	else if (error_code == MAP_WALL_ERROR)
		ft_putendl_fd("O mapa precisa ser fechado por paredes", 2);
	else if (error_code == MAP_CHAR_ERROR)
		ft_putendl_fd("O mapa precisa ter apenas P,C,E,0,1 e com bonus V", 2);
}
