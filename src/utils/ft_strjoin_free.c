/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:24:37 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/25 03:04:13 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin_free(char *s1, char *s2, int free_str)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (free_str == 1 || free_str == 3)
		free(s1);
	if (free_str == 2 || free_str == 3)
		free(s2);
	return (ret);
}
