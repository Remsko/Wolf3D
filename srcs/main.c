/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:30:14 by marvin            #+#    #+#             */
/*   Updated: 2018/07/15 19:15:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     main(int ac, char **av)
{
	t_env       e;
	t_visual    v;

	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	if (ac == 2)
	{
		if (wolf3d_parser(&e.map, av[1]) == FALSE)
		{
			//wolf3d_garbage(&e);
			ft_putendl("Parser error");
			return (1);
		}
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
		//wolf3d_garbage(&e);
	}
	else
		ft_putendl("usage: ./wolf3d <map path>");
	return (0);
}
