/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:12:21 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 03:39:12 by gabettin         ###   ########.fr       */
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
	result->x = 1;
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
	if (buffer == '\n' && (data->y == 1 ||
				(result = ft_node_to_array(first)) == 0))
		return (ft_free_node_chain(first));
	else if (buffer != '\n' && buffer != '\0')
		return (ft_free_node_chain(first) + (int)ft_free_simple(result));
	ft_free_node_chain(first);
	return (result);
}

char		*ft_know_line(int fb, t_bigdata *data)
{
	int		i;
	char	*result;
	int		to_read;
	int		readed;
	char	buffer;

	to_read = 0;
	if ((result = malloc(sizeof(char) * data->x)) == 0)
		return (0);
	while ((readed = read(fb, result + to_read, data->x - to_read)) != 0 &&
			to_read + readed != data->x)
		to_read += readed;
	to_read += readed;
	if (to_read != data->x)
		return (ft_free_simple(result));
	i = 0;
	while (i < data->x)
	{
		if (result[i] != data->e && result[i] != data->w)
			return (ft_free_simple(result));
		i++;
	}
	if (read(fb, &buffer, 1) != 1 || buffer != '\n')
		return (ft_free_simple(result));
	return (result);
}

char		**ft_matrix(int fb, t_bigdata **data)
{
	t_dnode	*first;
	t_dnode	*actual;
	char	**result;
	int		i;

	if ((*data = ft_line_info(fb)) == 0)
		return (0);
	if ((first = ft_new_dnode(ft_unknow_line(fb, *data))) == 0 ||
			first->data == 0)
		return (ft_free_node_and_dnode((void*)0, first));
	i = 0;
	actual = first;
	while (i < (*data)->y)
	{
		if ((actual->next = ft_new_dnode(ft_know_line(fb, *data))) == 0 ||
				actual->data == 0)
			return (ft_free_dnode_chain(first, 1));
		actual = actual->next;
		i++;
	}
	result = ft_dnode_to_array(first);
	ft_free_dnode_chain(first, 0);
	return (result);
}
