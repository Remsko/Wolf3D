/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:21:49 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 11:38:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_draw(t_env *e, t_visual *v)
{
    (void)e;
    SDL_RenderClear(v->renderer);
    SDL_SetRenderDrawColor(v->renderer, rand()%255, rand()%255, rand()%255, 255);
    SDL_RenderClear(v->renderer);
	SDL_RenderPresent(v->renderer);
}
