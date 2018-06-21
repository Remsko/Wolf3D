/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:34:06 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 16:57:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "wolf.h"

typedef struct	s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	direction;
	int			fov;
}				t_camera;

typedef struct	s_visual
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_screen	screen;
}				t_visual;

typedef struct  s_options
{
	t_bool		exit;
	t_bool		draw;
}               t_options;

typedef struct  s_inputs
{
	t_bool		up;
	t_bool		down;
	t_bool		left;
	t_bool		right;
}               t_inputs;

typedef struct  s_events
{
	t_options	options;
	t_inputs	inputs;
}               t_events;

typedef struct  s_env
{
	t_events	events;
	t_camera	cam;
}               t_env;

#endif
