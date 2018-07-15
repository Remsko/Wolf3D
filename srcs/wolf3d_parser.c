/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:55:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 16:31:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_bool  create_map(int **map, t_list *lst)
{
    t_list *tmp;

    tmp = lst;
    (void)map;
    ft_lstdel(&tmp, ft_deltab);
    return (TRUE);
}

t_bool  read_map(char **line, t_list **lst, int fd)
{
    char    **split;

    while (get_next_line(fd, line) > 0)
    {
        split = ft_strsplit(*line, ' ');
        ft_strdel(&(*line));
        if (*lst != NULL)
            ft_lstadd(lst, ft_lstnew((void *)split, 0));
        else
            *lst = ft_lstnew((void *)split, 0);
    }
    return (TRUE);
}

t_bool  wolf3d_parser(int **map, char *path)
{
    t_list  *lst;
    char    *line;
    int     fd;

    lst = NULL;
    if ((fd = open(path, O_RDONLY)) <= 0)
        return (TRUE);
    if (read_map(&line, &lst, fd) == FALSE)
        return(FALSE);
    if (create_map(map, lst) == FALSE)
        return (FALSE);
    if (close(fd) == -1)
        return (FALSE);
    return (TRUE);
}