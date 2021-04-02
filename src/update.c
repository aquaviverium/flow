/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/08/05 21:08:49 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	clean_particle_array(t_app_context *app_context, int curr_amount)
{
	int	i;
	int	total_particles;
	t_particulate	particle;

	i = 0;
	total_particles = 0;
	while (i < curr_amount)
	{
		particle = app_context->particles[i];

		if (particle.age != -1)
		{
			app_context->particle_buffer[total_particles] = particle;
			total_particles++;
		}
		i++;
	}

	i = 0;
	bzero(app_context->particles, sizeof(*(app_context->particles)) * app_context->particle_cap);
	while (i < total_particles)
	{
		app_context->particles[i] = app_context->particle_buffer[i];
		i++;
	}
	app_context->current_particles = i;
}

void		update_app_state(t_app_context *app_state)
{
	int	i;
	int	total_particles;

	i = 0;
	total_particles = app_state->current_particles;

	if (total_particles >= app_state->particle_cap)
		printf(RED"Cap Reached\n");
	while (i < total_particles)
	{
		update_particle(&(app_state->particles[i]));
		i++;
	}


	app_state->time++;
	if (app_state->time >= 1000)
		app_state->time = 0;

	clean_particle_array(app_state, total_particles);

	if (app_state->time % 20 == 0)
	{
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH,  25}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH,  50}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH,  75}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 100}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 125}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 150}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 175}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 200}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 225}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 250}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 275}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 300}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 325}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 350}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 375}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 400}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 425}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 450}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 475}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 500}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 525}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 550}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 575}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 600}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 625}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 650}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 675}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 700}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 725}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 750}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 775}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 800}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 825}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 850}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 875}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 900}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 925}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 950}, app_state->flow);
		spawn_particle(&(app_state->particles[app_state->current_particles]), (t_vector2f){WIN_WIDTH, 975}, app_state->flow);
	}
}
