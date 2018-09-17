/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:12:21 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 17:02:11 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_line_opp.h"
#include "ft_node_opp.h"
#include "ft_memory_opp.h"

t_bigdata	*ft_line_info(int fb)
{
	char		buffer;
	t_bigdata	*result;

	if ((result = malloc(sizeof(t_bigdata))) == 0)
		return (0);
	result->X = 0;
	buffer = 0;
	while (read(fb, &buffer, 1) == 1 && (buffer >= '0' && buffer <= '9'))
		result->X = (result->X * 10) + (buffer - '0');
	if (result->X == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->E = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->W = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->S = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer != '\n')
		return (ft_free_simple(result));
	return (result);
}
