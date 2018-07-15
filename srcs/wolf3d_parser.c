/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:55:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 16:12:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_bool  create_map()
{
    return (TRUE);
}

t_bool  read_map(int **map, char **line, int fd)
{
    (void)map;
    while (get_next_line(fd, line) > 0)
        ft_strdel(&(*line));
    return (TRUE);
}

t_bool  wolf3d_parser(int **map, char *path)
{
    char    *line;
    int     fd;

    if ((fd = open(path, O_RDONLY)) <= -1)
        return (TRUE);
    if (read_map(map, &line, fd) == FALSE)
        return(FALSE);
    if (create_map() == FALSE)
        return (FALSE);
    if (close(fd) == -1)
        return (FALSE);
    return (TRUE);
}