/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:59:11 by home              #+#    #+#             */
/*   Updated: 2020/08/05 20:06:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define CLIP_DIST (20)

bool	out_of_bounds(t_particulate *self)
{
	bool	result;

	result = false;
	if (self->pos.x <= CLIP_DIST + 30)
		result = true;
	else if (self->pos.x >= WIN_WIDTH + CLIP_DIST)
		result = true;
	else if (self->pos.y <= -CLIP_DIST)
		result = true;
	else if (self->pos.y >= WIN_HEIGHT + CLIP_DIST)
		result = true;
	return (result);
}

void	spawn_particle(t_particulate *self, t_vector2f pos, t_vector2f vel)
{
	get_app_context()->current_particles++;

	self->age = 0;

	self->pos = pos;
	self->vel = vel;

	printf("Spawned %d\n", get_app_context()->current_particles);
}

void	update_particle(t_particulate *self)
{
	self->pos.x += self->vel.x;
	self->pos.y += self->vel.y;

	self->age++;

	if (out_of_bounds(self) == true)
		despawn_particle(self);
}

void	despawn_particle(t_particulate *self)
{
	t_app_context	*app;

	app = get_app_context();
	app->current_particles--;
	self->age = -1;
}
