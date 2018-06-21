/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:00:51 by marvin            #+#    #+#             */
/*   Updated: 2018/06/21 17:36:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    sdl_loop(t_env *e, t_visual *v)
{
	unsigned int	time;
	float			angle;

	time = 0;
	angle = 10.0f;
	ft_bzero(&e->events, sizeof(t_events));
	e->cam = (t_camera){(t_vector){5, 5}, (t_vector){-1, 0}, 60};
	while (e->events.options.exit == FALSE)
	{
		ft_bzero(&e->events.inputs, sizeof(t_inputs));
		if (e->events.options.draw == FALSE)
		{
			sdl_draw(v, &e->cam);
			e->events.options.draw = TRUE;
		}
		sdl_fps(&time);
		sdl_event(&e->events);
		if (e->events.inputs.up == TRUE)
		{
			e->cam.origin.x += e->cam.direction.x * 0.5f;
			e->cam.origin.y += e->cam.direction.y * 0.5f;
		}
		else if (e->events.inputs.down == TRUE)
		{
			e->cam.origin.x -= e->cam.direction.x * 0.5f;
			e->cam.origin.y -= e->cam.direction.y * 0.5f;
		}
		else if (e->events.inputs.left == TRUE)
		{
			if ((angle += 10.0f) == 370.0f)
				angle = 0.0f;
			float tmpX = e->cam.direction.x;
			float tmpY = e->cam.direction.y;
			float tmpAngle = angle / 180.0f * M_PI;
			e->cam.direction.x = tmpX * cosf(tmpAngle) - tmpY * sinf(tmpAngle);
			e->cam.direction.y = tmpX * sinf(tmpAngle) + tmpY * cosf(tmpAngle);
		}
		else if (e->events.inputs.right == TRUE)
		{
			if ((angle -= -10.0f) == -10.0f)
				angle = 360.0f;
			float tmpX = e->cam.direction.x;
			float tmpY = e->cam.direction.y;
			float tmpAngle = angle / 180.0f * M_PI;
			e->cam.direction.x = tmpX * cosf(tmpAngle) - tmpY * sinf(tmpAngle);
			e->cam.direction.y = tmpX * sinf(tmpAngle) + tmpY * cosf(tmpAngle);
		}
	}
}
