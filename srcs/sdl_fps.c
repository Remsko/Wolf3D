/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:45:15 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 10:34:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sdl_fps(void)
{
	static int			fps;
	static unsigned int	last_time;
	unsigned int		current_time;

	++fps;
	current_time = SDL_GetTicks();
	if (current_time > last_time + (unsigned int)1000)
	{
		ft_putstr("fps: ");
		ft_putnbr(fps);
		ft_putchar('\n');
		fps = 0;
		last_time = current_time;
	}
}
