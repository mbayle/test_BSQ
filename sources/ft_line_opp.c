/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:12:21 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 17:56:18 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_line_opp.h"
#include "ft_node_opp.h"
#include "ft_memory_opp.h"
#include "libft.h"

t_bigdata	*ft_line_info(int fb)
{
	char		buffer;
	t_bigdata	*result;

	if ((result = malloc(sizeof(t_bigdata))) == 0)
		return (0);
	buffer = 0;
	result->x = 0;
	result->y = 0;
	while (read(fb, &buffer, 1) == 1 && (buffer >= '0' && buffer <= '9'))
		result->y = (result->y * 10) + (buffer - '0');
	if (result->y == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->e = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->w = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer == '\n' || buffer == '\0')
		return (ft_free_simple(result));
	result->s = buffer;
	if (read(fb, &buffer, 1) == 0 || buffer != '\n')
		return (ft_free_simple(result));
	return (result);
}

char		*ft_unknow_line(int fb, t_bigdata *data)
{
	char	buffer;
	t_node	*first;
	t_node	*actual;
	char	*result;

	first = 0;
	if (read(fb, &buffer, 1) != 1 || (buffer != data->e && buffer != data->w) ||
			(first = ft_new_node(buffer)) == 0)
		return (0);
	actual = first;
	while (read(fb, &buffer, 1) == 1 && (buffer == data->e ||
				buffer == data->w))
	{
		(data->x)++;
		actual->next = ft_new_node(buffer);
		actual = actual->next;
	}
	if (buffer == '\0' && data->x != 1)
		return (ft_free_node_chain(first));
	else if (buffer == '\n' && (data->x == 1 ||
				(result = ft_node_to_array(first))) == 0)
		return (ft_free_node_chain(first));
	else if (buffer != '\n' && buffer != '\0')
		return (ft_free_node_chain(first));
	return (result);
}
