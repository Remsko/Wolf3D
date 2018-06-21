/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:00:51 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 12:02:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_loop(t_env *e, t_visual *v)
{
	unsigned int time;

	time = SDL_GetTicks();
    ft_bzero(&e->events, sizeof(t_events));
    while (e->events.options.exit == FALSE)
    {
        if (e->events.options.draw == FALSE)
        {
            sdl_draw(e, v);
            e->events.options.draw = TRUE;
        }
		sdl_fps(&time);
        sdl_event(&e->events);
    }
}
