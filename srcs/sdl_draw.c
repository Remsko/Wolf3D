/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:21:49 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 17:02:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_draw(t_visual *v, t_camera *cam)
{
    SDL_RenderClear(v->renderer);
    SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
    wolf3d_draw(v, cam);
    SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderPresent(v->renderer);
}
