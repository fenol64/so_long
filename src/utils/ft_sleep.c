/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:12:03 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 06:12:15 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sleep(int seconds)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < seconds)
	{
		while (j < 100000000)
			j++;
		j = 0;
		i++;
	}
}