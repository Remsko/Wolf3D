/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:30:14 by marvin            #+#    #+#             */
/*   Updated: 2018/07/15 16:05:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     main(int ac, char **av)
{
	t_env       e;
	t_visual    v;
	int i = 0;
	int j = 0;

	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	e.map = (int **)malloc(sizeof(int *) * 10);
	while (i < 10)
	{
		e.map[i] = (int *)malloc(sizeof(int) * 10);
		j = 0;
		while (j < 10)
		{
			if (j == 0 || j == 9 || i == 0 || i == 9)
				e.map[i][j] = 1;
			else
				e.map[i][j] = 0;
			++j;
		}
		++i;
	}
	e.map[5][5] = 1;
	if (ac == 2)
	{
		if (wolf3d_parser(e.map, av[1]) == FALSE)
			return (1);
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
	}
	else
		ft_putendl("usage: ./wolf3d <map path>");
	return (0);
}
