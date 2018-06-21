/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:30:14 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 16:51:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     main(int ac, char **av)
{
	t_env       e;
	t_visual    v;

	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	if (ac == 1)
	{
		//if (parser(&e) == ERROR)
		//	return (1);
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
	}
	else
		printf("usage: %s", av[0]);
	return (0);
}
