/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:34:03 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 11:20:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

#include "wolf.h"

/* GRAPHICS */

void    sdl_loop(t_env *e, t_visual *v);

void    sdl_draw(t_env *e, t_visual *v);

void	sdl_event(t_events *e);

void	sdl_destroy(t_visual *v);

void    sdl_init(t_visual *v);

#endif
