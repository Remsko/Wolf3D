/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:41:41 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 10:35:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double get_frametime(void)
{
	static unsigned int time;
	static unsigned int old;

	old = time;
	time = SDL_GetTicks();
	return ((time - old) / 1000.0);
}

static void	z_axis_rot(t_vector *vec, double rad_angle)
{
	double tmp_x;

	tmp_x = vec->x;
	vec->x = tmp_x * cos(rad_angle) - vec->y * sin(rad_angle);
	vec->y = tmp_x * sin(rad_angle) + vec->y * cos(rad_angle);
}

void	wolf3d_actions(t_env *e)
{
	double movespeed;
	double rotspeed;

	rotspeed = get_frametime() * 3.0;
	movespeed = rotspeed * 2.0;
	if (e->events.keys[SDL_SCANCODE_UP] == TRUE)
	{
		if (e->map[(int)(e->cam.origin.x + e->cam.direction.x * movespeed)][(int)e->cam.origin.y] == 0)
			e->cam.origin.x += (e->cam.direction.x * movespeed);
		if (e->map[(int)e->cam.origin.x][(int)(e->cam.origin.y + e->cam.direction.y * movespeed)] == 0)
			e->cam.origin.y += (e->cam.direction.y * movespeed);
	}
	else if (e->events.keys[SDL_SCANCODE_DOWN] == TRUE)
	{
		if (e->map[(int)(e->cam.origin.x - e->cam.direction.x * movespeed)][(int)e->cam.origin.y] == 0)
			e->cam.origin.x -= (e->cam.direction.x * movespeed);
		if (e->map[(int)e->cam.origin.x][(int)(e->cam.origin.y - e->cam.direction.y * movespeed)] == 0)
			e->cam.origin.y -= (e->cam.direction.y * movespeed);
	}
	else if (e->events.keys[SDL_SCANCODE_LEFT] == TRUE)
	{
		z_axis_rot(&e->cam.direction, rotspeed);
		z_axis_rot(&e->cam.plane, rotspeed);
	}
	else if (e->events.keys[SDL_SCANCODE_RIGHT] == TRUE)
	{
		z_axis_rot(&e->cam.direction, -rotspeed);
		z_axis_rot(&e->cam.plane, -rotspeed);
	}
}
