/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2021/03/12 23:43:38 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_H
# define OUT_H

# include <stdbool.h>
# include <unistd.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include "color.h"
# include "more_math.h"

# define WIN_TITLE "FLOW"

# define WIN_WIDTH  (1000)
# define WIN_HEIGHT (1000)

# define WIN_POS_X (2000)
# define WIN_POS_Y (50)

# define UNIT (10)

typedef struct	s_display
{
	bool			active;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

t_display	*get_display(void);

void		SDLU_start(t_display *dest);
void		SDLU_close(void);

void		ctoRGB(int color, int *r, int *g, int *b);
void		SDLU_SetRenderDrawColor(int color);

void		out(void);

void		set_color(int val, int *r, int *g, int *b);
int			clerp(int color1, int color2, int t, int tmax);

#endif
