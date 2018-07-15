/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:34:03 by marvin            #+#    #+#             */
/*   Updated: 2018/07/15 19:20:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

#include "wolf.h"

/* PARSING */

t_bool  wolf3d_parser(t_map *map, char *path);

/* GRAPHICS */

void    sdl_loop(t_env *e, t_visual *v);

void    sdl_draw(t_visual *v, t_camera *cam, int **map);

void	sdl_event(t_events *e);

void	sdl_destroy(t_visual *v);

void    sdl_init(t_visual *v);

void    sdl_fps();

/* WOLF3D */

void	wolf3d_draw(t_visual *v, t_camera *cam, int **map);

void	wolf3d_actions(t_env *e);

void    wolf3d_garbage(t_env *e);

#endif
