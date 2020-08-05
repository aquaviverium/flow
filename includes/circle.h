/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:39:51 by home              #+#    #+#             */
/*   Updated: 2020/08/01 21:42:31 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_H
# define CIRCLE_H

# include "vector.h"

typedef struct	circle
{
	t_vector2f	pos;
	double		radius;
}				t_circle;

#endif
