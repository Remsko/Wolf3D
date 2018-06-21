/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 22:34:00 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 11:41:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sdl_event(t_events *e)
{
	SDL_Event   event;

    while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			e->options.exit = TRUE;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			e->options.exit = TRUE;
		e->options.draw = FALSE;
	}
}
