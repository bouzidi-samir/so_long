/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:02:22 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/23 14:03:37 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    t_mapform   *mapcheck;
    
    mapcheck = malloc(sizeof(*mapcheck));
    if (mapcheck == NULL)
        return (-1);
    if (check_map(argv[1], mapcheck))
    {  
        ft_putstr_fd("error\n", 1);
        free(mapcheck);
        return (1);
    }
    
    free(mapcheck);
    return (0);
}