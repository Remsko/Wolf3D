/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 22:34:00 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 17:21:25 by rpinoit          ###   ########.fr       */
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
		else if (event.key.keysym.sym == SDLK_UP)
			e->inputs.up = TRUE;
		else if (event.key.keysym.sym == SDLK_DOWN)
			e->inputs.down = TRUE;
		else if (event.key.keysym.sym == SDLK_LEFT)
			e->inputs.left = TRUE;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			e->inputs.right = TRUE;
		e->options.draw = FALSE;
	}
}
