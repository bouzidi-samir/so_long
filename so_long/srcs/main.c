/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:02:22 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/20 08:54:11 by samirbouzid      ###   ########.fr       */
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

void	init_game(t_mapform *mapcheck, t_data *g)
{
	g = malloc(sizeof(*g));
	if (g == NULL)
		return ;
	g->mlx = mlx_init();
	g->width = mapcheck->width * SIZE_BLOC;
	g->height = mapcheck->height * SIZE_BLOC;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "so_long");
	g->img = mlx_new_image(g->mlx, g->width, g->height);
	g->colectible = mapcheck->colectible;
	g->end = 0;
	g->score = 0;
	g->path.vide = "img/fond.xpm";
	g->path.mur = "img/mur.xpm";
	g->path.obj = "img/objectif.xpm";
	g->path.pla = "img/mario_droite1.xpm";
	g->path.exit = "img/exit.xpm";
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	get_tab(g, mapcheck);
	map_parsing(mapcheck, g->map, g);
	free_map(mapcheck);
	free(mapcheck);
	mlx_hook(g->win, 17, 0, destroy_window, g);
	mlx_hook(g->win, 2, 1L << 0, moove_player, g);
	mlx_hook(g->win, 3, 1L << 1, key_release, g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	t_mapform	*mapcheck;
	t_data		*g;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nYou must give one argument\n", 2);
		return (1);
	}
	mapcheck = malloc(sizeof(*mapcheck));
	if (mapcheck == NULL)
		return (-1);
	g = NULL;
	if (check_map(argv[1], mapcheck))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(mapcheck->error_message, 2);
		free_map(mapcheck);
		free(mapcheck);
		return (1);
	}
	init_game(mapcheck, g);
	free_tab(g);
	free(g);
	return (0);
}
