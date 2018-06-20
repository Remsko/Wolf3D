/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:21:49 by marvin            #+#    #+#             */
/*   Updated: 2018/06/20 23:21:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_draw(t_env *e, t_visual *v)
{
    (void)e;
    SDL_SetRenderDrawColor(v->renderer, 100, 100, 100, 255);
    SDL_RenderClear(v->renderer);
	SDL_RenderPresent(v->renderer);
}