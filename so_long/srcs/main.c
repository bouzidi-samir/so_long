/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:02:22 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/15 21:53:22 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(char *file, t_mapform *mapcheck)
{
	mapcheck->error = 0;
	mapcheck->height = 0;
	mapcheck->height = count_lines(file);
	mapcheck->characters = "01CEP";
	mapcheck->player = 0;
	mapcheck->colectible = 0;
	mapcheck->exit = 0;
	mapcheck->error_message = NULL;
	mapcheck->map = malloc(sizeof(char *) * mapcheck->height);
	if (!mapcheck->map)
		return (-1);
	return (0);
}

int	init_game(t_mapform *mapcheck, t_data *game)
{
	game = malloc(sizeof(*game));
	if (game == NULL)
		return (-1);
	game->mlx = mlx_init();
	game->width = mapcheck->width * SIZE_BLOC;
	game->height = mapcheck->height * SIZE_BLOC;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	game->colectible = mapcheck->colectible;
	game->end = 0;
	game->path.vide = "img/fond.xpm";
    game->path.mur = "img/mur.xpm";
    game->path.obj = "img/objectif.xpm";
    game->path.play = "img/mario_droite1.xpm";
    game->path.exit = "img/exit.xpm";
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (get_tab(game, mapcheck))
		return (-1);
	map_parsing(mapcheck, game->map, game);
	free_map(mapcheck);
	free(mapcheck);
	mlx_hook(game->win, 2, 1L << 0, moove_player, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mapform	*mapcheck;
	t_data		*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nYou must give one argument\n", 2);
		return (1);
	}
	mapcheck = malloc(sizeof(*mapcheck));
	if (mapcheck == NULL)
		return (-1);
	game = NULL;
	if (check_map(argv[1], mapcheck))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mapcheck->error_message, 2);
		free_map(mapcheck);
		free(mapcheck);
		return (1);
	}
	if (mapcheck == NULL)
		return (-1);
	if (init_game(mapcheck, game))
		return (-1);
	free_tab(game);
	free(game);
	return (0);
}
