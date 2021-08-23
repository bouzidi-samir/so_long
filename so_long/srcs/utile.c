/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:14:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/21 15:36:21 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_mapform *mapcheck)
{
	int		i;

	i = -1;
	while (++i < mapcheck->height)
	{
		free(mapcheck->map[i]);
	}
	free(mapcheck->map);
}

