/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/08/05 01:39:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	SDL_RenderDrawPoint_Wrapper(void *ptr, int x, int y)
{
	SDL_Renderer	*renderer;

	renderer = ptr;
	SDL_RenderDrawPoint(renderer, x, y);
}

void	draw_circle(t_vector2f pos, int age)
{
	int			i;
	t_display	*display;
	t_circle	circle;
	int			r, g, b;

	i = 0;
	circle.pos = pos;
	display = get_display();
	set_color(age, &r, &g, &b);
	SDL_SetRenderDrawColor(get_display()->renderer, r, g, b, SDL_ALPHA_OPAQUE);
	while (i < 10)
	{
		circle.radius = i;
		out_circle(circle, SDL_RenderDrawPoint_Wrapper, display->renderer);
		i++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void	render_particles(void)
{
	int				i;
	t_display		*display;
	t_app_context	*app;

	i = 0;
	app = get_app_context();
	display = get_display();

	t_vector2f pos;

	static int	age;

	pos.x = 500;
	pos.y = 500;

	draw_circle(pos, age);

	age++;
	// while (i < app->current_particles)
	// {
	// 	i++;
	// }
}

void	render_loop(void)
{
	t_display	*display;

	display = get_display();

	render_particles();

	SDLU_SetRenderDrawColor(0x000000);
}

/**
* Function that shall handle the visualization of the simulation.
* Note that there should be no params passed in to keep code contact
* with the simulation as little.
*
* This is done so that the graphical aspect of this project shall
* be used as a module that can be removed, replaced, and easily
* changed without affecting the simulation.
*
**/
void	out(void)
{
	render_loop();
	SDL_RenderPresent(get_display()->renderer);
	SDL_RenderClear(get_display()->renderer);

	// usleep(500000);
}
