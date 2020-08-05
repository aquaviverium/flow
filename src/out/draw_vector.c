/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 01:34:52 by home              #+#    #+#             */
/*   Updated: 2020/08/05 00:31:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "out.h"

void	draw_vector(t_vector2f start, t_vector2f end)
{
	int	x1, y1, x2, y2;

	x1 = (start.x * UNIT) + WIN_WIDTH / 2;
	y1 = -1 * (start.y * UNIT) + WIN_HEIGHT / 2;

	x2 = (end.x * UNIT) + WIN_WIDTH / 2;
	y2 = -1 * (end.y * UNIT) + WIN_HEIGHT / 2;

	SDL_RenderDrawLine(get_display()->renderer, x1, y1, x2, y2);
}

