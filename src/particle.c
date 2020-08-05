/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   particle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 01:59:11 by home              #+#    #+#             */
/*   Updated: 2020/08/05 02:19:37 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	spawn_particle(t_particulate *self)
{
	t_vector2f	pos;
	t_vector2f	vel;

	pos.x = 500;
	pos.x = 500;

	vel.y = 10;
	vel.y = 10;

	self->age = 0;

	self->pos = pos;
	self->vel = vel;
}

void	update_particle(t_particulate *self)
{
	self->pos.x += self->vel.x;
	self->pos.y += self->vel.y;

	//boundary_check

	self->age++;
}

void	despawn_partile(t_particulate *self)
{
	t_app_context	*app;

	app = get_app_context();
	app->current_particles--;
	self->age = -1;
}
