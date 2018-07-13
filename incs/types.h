/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:34:06 by marvin            #+#    #+#             */
/*   Updated: 2018/07/13 16:01:19 by rpinoit          ###   ########.fr       */
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
	double		x;
	double		y;
}				t_vector;

typedef struct	s_camera
{
	t_vector	origin;
	t_vector	direction;
	t_vector	plane;
}				t_camera;

typedef struct	s_visual
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_screen		screen;
}				t_visual;

typedef struct  s_options
{
	t_bool		exit;
	t_bool		draw;
	t_bool		game;
	t_bool		intro;
}               t_options;

typedef struct  s_events
{
	t_options			options;
	const unsigned char	*keys;
}               t_events;

typedef struct  s_env
{
	t_events	events;
	t_camera	cam;
	int			**map;
}               t_env;

#endif
