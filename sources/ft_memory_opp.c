/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_opp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:13:48 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 22:50:29 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory_opp.h"

void	*ft_free_node_chain(t_node *first)
{
	t_node	*actual;
	t_node	*buffer;

	actual = first;
	while (actual != 0)
	{
		buffer = actual;
		actual = actual->next;
		free(buffer);
	}
	return (0);
}

void	*ft_free_dnode_chain(t_dnode *first, int and_data)
{
	t_dnode	*actual;
	t_dnode	*buffer;

	actual = first;
	while (actual != 0)
	{
		buffer = actual;
		actual = actual->next;
		if (and_data != 0)
			free(buffer->data);
		free(buffer);
	}
	return (0);
}

void	*ft_free_martis(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i++]);
	}
	free(array);
	return (0);
}

void	*ft_free_simple(void *object)
{
	free(object);
	return (0);
}

void	*ft_free_node_and_dnode(t_node *node, t_dnode *dnode)
{
	if (node)
		free(node);
	if (dnode)
		free(dnode);
	return (0);
}
