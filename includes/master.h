/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/08/05 20:06:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>
# include <strings.h>
# include <stdbool.h>

# include <SDL_image.h>

# include "structs.h"
# include "more_math.h"
# include "out.h"

t_app_context	*get_app_context(void);
t_app_context	*set_app_context(t_app_context *app_context);

void	process_user_input(t_app_context *app_state);
void	update_app_state(t_app_context *app_state);

void	update_particle(t_particulate *self);
void	despawn_particle(t_particulate *self);
void	spawn_particle(t_particulate *self, t_vector2f pos, t_vector2f vel);


#endif
