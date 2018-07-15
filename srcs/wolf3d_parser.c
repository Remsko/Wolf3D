/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:55:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 16:04:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_bool  wolf3d_parser(int **map, char *path)
{
    int fd;

    if ((fd = open(path, O_RDONLY)) <= -1)
        return (TRUE);
    (void)map;
    if (close(fd) == -1)
        return (FALSE);
    return (TRUE);
}