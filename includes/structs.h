/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2021/03/12 23:39:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <SDL2/SDL.h>
# include <stdbool.h>

# include "more_math.h"

typedef struct	s_particulate
{
	int			age;

	t_vector2f	pos;
	t_vector2f	vel;
}				t_particulate;

typedef struct	s_app_context
{
	int				time;
	int				particle_cap;
	int				current_particles;

	t_particulate	*particle_buffer;
	t_particulate	*particles;

	t_vector2f		flow;

}				t_app_context;

#endif
