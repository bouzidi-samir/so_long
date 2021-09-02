/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:14:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/01 14:06:36 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_tab(t_data	*game, t_mapform *mapcheck)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(t_bloc*) * mapcheck->height);
	if (game->map == NULL)
		return (1);
	while (i <= mapcheck->height)
	{
		game->map[i] = malloc(sizeof(t_bloc) * mapcheck->width);
		i++;
	}
	
	return (0);
}

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



