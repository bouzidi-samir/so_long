/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:48 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/23 14:12:29 by samirbouzid      ###   ########.fr       */
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
    int error;
} t_mapform;



int check_map(char *file, t_mapform *mapcheck);
void fill_map(char *file, t_mapform *mapcheck);
void	free_map(t_mapform *mapcheck);
int check_characters(t_mapform *mapcheck);
int check_square(t_mapform *mapcheck);
int check_wall(t_mapform *mapcheck);

#endif
