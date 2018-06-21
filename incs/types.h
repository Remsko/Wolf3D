/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:34:06 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 11:21:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "wolf.h"

typedef struct	s_visual
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
}				t_visual;

typedef struct  s_options
{
	t_bool  exit;
	t_bool  draw;
}               t_options;

typedef struct  s_inputs
{
	t_bool  up;
	t_bool  down;
	t_bool  left;
	t_bool  right;
}               t_inputs;

typedef struct  s_events
{
	t_options   options;
	t_inputs    inputs;
}               t_events;

typedef struct  s_env
{
	t_events     events;
}               t_env;

#endif
