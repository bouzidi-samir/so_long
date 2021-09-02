/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:48 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/09/02 09:52:06 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE_BLOC 31

# include "so_long.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>

typedef struct s_mapform
{
    char    **map;
    char    *characters;
    int height;
    int width;    
    char    *top;
    char    *bottom;
    int player;
    int colectible;
    int exit;
    int error;
} t_mapform;

typedef struct	s_bloc 
{
	void	*img;
    char    type;
    int x;
    int y;   
}				t_bloc;

typedef struct	s_data  
{
	int width;
    int height;
    void    *mlx;
    void    *win;
    void	*img;
    struct s_bloc  **map;

}				t_data;

int check_map(char *file, t_mapform *mapcheck);
int fill_map(char *file, t_mapform *mapcheck);
void	free_map(t_mapform *mapcheck);
int check_characters(t_mapform *mapcheck);
int check_square(t_mapform *mapcheck);
int check_wall(t_mapform *mapcheck);
int init_game(t_mapform *mapcheck);
void map_parsing(t_mapform *mapcheck, t_bloc **mapgame, t_data  *game);
int	get_tab(t_data *game, t_mapform *mapcheck);
void    put_blocs(t_bloc element, t_data  *game, int x, int y);

#endif
