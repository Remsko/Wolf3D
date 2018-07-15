/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:55:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 19:10:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_bool  create_map(t_map *map, t_list *lst)
{
    t_list  *tmp;
    char    **split;
    int     x;
    int     y;

    y = 0;
    tmp = lst;
    if ((map->array = (int **)malloc(sizeof(int *) * map->infos.height)) == NULL) 
        return (FALSE);
    while (lst != NULL)
    {
        x = 0;
        split = (char **)lst->content;
        if ((map->array[y] = (int *)malloc(sizeof(int) * map->infos.width)) == NULL) 
            return (FALSE);
        while (x < map->infos.width)
        {
            map->array[y][x] = split[x] ? ft_atoi(split[x]) : 1;
            ++x;
        }
        y++;
        lst = lst->next;
    }
    ft_lstdel(&tmp, ft_deltab);
    return (TRUE);
}

t_bool  read_map(char **line, t_list **lst, t_infos *infos, int fd)
{
    char    **split;

    infos->height = 0;
    infos->width = 0;
    while (get_next_line(fd, line) > 0)
    {
        split = ft_strsplit(*line, ' ');
        if (ft_tablen(split) > infos->width)
            infos->width = ft_tablen(split);
        ++infos->height;
        if (*lst != NULL)
            ft_lstadd(lst, ft_lstnew((void *)split, 0));
        else
            *lst = ft_lstnew((void *)split, 0);
        ft_strdel(&(*line));
    }
    return (TRUE);
}

t_bool  wolf3d_parser(t_map *map, char *path)
{
    t_list  *lst;
    char    *line;
    int     fd;

    lst = NULL;
    if ((fd = open(path, O_RDONLY)) <= 0)
        return (TRUE);
    if (read_map(&line, &lst, &map->infos, fd) == FALSE)
        return(FALSE);
    if (create_map(map, lst) == FALSE)
        return (FALSE);
    if (close(fd) == -1)
        return (FALSE);
    return (TRUE);
}