/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:23:44 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/15 10:30:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf3d_draw(t_visual *v, t_camera *cam, int **map)
{
	int w = v->screen.width;
	int h = v->screen.height;

	double posX = cam->origin.x, posY = cam->origin.y;  //x and y start position
	double dirX = cam->direction.x, dirY = cam->direction.y; //initial direction vector

	for(int x = 0; x < w; x++)
	{
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = dirX + cam->plane.x * cameraX;
		double rayDirY = dirY + cam->plane.y * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(h / perpWallDist);

		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		int red = 255;

		if (side == 1)
			red = red / 2;
		int y = drawStart;
		
		double coef = perpWallDist > 10 ? 0.0 : (1 - (double)(perpWallDist / 10));
		SDL_SetRenderDrawColor(v->renderer, red * coef, 0, 0, 255);
		while (y < drawEnd)
		{
			SDL_RenderDrawPoint(v->renderer, x, y);
			++y;
		}
		/*
		SDL_SetRenderDrawColor(v->renderer, 95, 105, 90, 255);
		while (y < h)
		{
			SDL_RenderDrawPoint(v->renderer, x, y);
			++y;
		}
		*/
	}
}
