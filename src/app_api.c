/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_api.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 00:50:30 by home              #+#    #+#             */
/*   Updated: 2020/08/05 01:01:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

t_app_context	*set_app_context(t_app_context *app_context)
{
	static t_app_context *ptr;

	if (ptr == NULL && app_context != NULL)
		ptr = app_context;

	return (ptr);
}

t_app_context	*get_app_context(void)
{
	t_app_context *result;

	result = set_app_context(NULL);
	return (result);
}
