/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2020/08/05 20:44:59 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"
#include "structs.h"

#include "master.h"

void	process_user_input(t_app_context *app_state)
{
	SDL_Event		e;
	const Uint8		*keystate;
	t_app_context	*app;

	app = get_app_context();
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			get_display()->active = false;
			break ;
		}
		else if (e.key.keysym.scancode == SDL_SCANCODE_UP)
			app->flow.y -= .05;
		else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
			app->flow.y += .05;
		else if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
			app->flow.x -= .05;
		else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			app->flow.x += .05;
	}

	if (app->flow.x >= 0)
		app->flow.x = -.1;
	keystate = SDL_GetKeyboardState(NULL);
	(void)app_state;
}
