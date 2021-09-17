/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:14:05 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/17 12:11:07 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	int		rcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	count = 1;
	while (1)
	{
		rcount = read(fd, &c, 1);
		if (rcount == 0)
			break ;
		if (rcount < 0)
			return (-1);
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	get_tab(t_data	*game, t_mapform *mapcheck)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(t_bloc *) * mapcheck->height);
	if (game->map == NULL)
		return (1);
	while (i <= mapcheck->height)
	{
		game->map[i] = malloc(sizeof(t_bloc) * mapcheck->width);
		i++;
	}	
	return (0);
}

void	free_tab(t_data *game)
{
	int	i;

	i = 0;
	while (i <= game->height / SIZE_BLOC)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
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

int	end_game(t_data *game)
{
	free_tab(game);
	free(game);
	exit(0);
	return (0);
}
