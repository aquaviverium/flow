/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/08/05 01:54:21 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	app_context_initialize(t_app_context *app_state)
{
	set_app_context(app_state);

	app_state->particle_cap = 50;
	app_state->current_particles = 0;

	app_state->particles = calloc(app_state->particle_cap, sizeof(*(app_state->particles)));
	app_state->particle_buffer = calloc(app_state->particle_cap, sizeof(*(app_state->particle_buffer)));
}

int	main(void)
{
	t_app_context	app_state;

	app_context_initialize(&app_state);

	while (get_display()->active == true)
	{
		process_user_input(&app_state);

		update_app_state(&app_state);

		out();
	}
	return (0);
}
