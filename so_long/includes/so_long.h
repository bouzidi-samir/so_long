/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:48 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/24 11:53:55 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

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



int check_map(char *file, t_mapform *mapcheck);
int fill_map(char *file, t_mapform *mapcheck);
void	free_map(t_mapform *mapcheck);
int check_characters(t_mapform *mapcheck);
int check_square(t_mapform *mapcheck);
int check_wall(t_mapform *mapcheck);

#endif
