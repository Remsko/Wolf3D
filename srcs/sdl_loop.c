/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:00:51 by marvin            #+#    #+#             */
/*   Updated: 2018/07/13 16:01:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_loop(t_env *e, t_visual *v)
{
	ft_bzero(&e->events, sizeof(t_events));
	e->cam = (t_camera){(t_vector){5.0f, 5.0f}, (t_vector){-1.0f, 0.0f}, (t_vector){0.0f, 0.66f}};
	while (e->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&e->events);
		sdl_draw(v, &e->cam, e->map);
		wolf3d_actions(e);
	}
}
