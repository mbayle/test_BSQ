/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:56:34 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 17:55:32 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node_opp.h"
#include "libft.h"

t_node	*ft_new_node(char data)
{
	t_node	*result;

	if ((result = malloc(sizeof(t_node))) == 0)
		return (0);
	result->data = data;
	result->next = 0;
	return (result);
}

t_dnode	*ft_new_dnode(char *data)
{
	t_dnode	*result;

	if ((result = malloc(sizeof(t_dnode))) == 0)
		return (0);
	result->data = data;
	result->next = 0;
	return (result);
}

char	*ft_node_to_array(t_node *first)
{
	char	*result;
	int		counter;
	int		i;
	t_node	*actual;

	counter = 0;
	actual = first;
	while (actual->next != 0)
	{
		actual = actual->next;
		counter++;
	}
	if ((result = malloc(sizeof(char) * (counter + 1))) == 0)
		return (0);
	i = 0;
	actual = first;
	while (i <= counter)
	{
		result[i++] = actual->data;
		actual = actual->next;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_dnode_to_array(t_dnode *first)
{
	char	**result;
	int		counter;
	int		i;
	t_dnode	*actual;

	counter = 0;
	actual = first;
	while (actual->next != 0)
	{
		actual = actual->next;
		counter++;
	}
	if ((result = malloc(sizeof(char*) * (counter + 1))) == 0)
		return (0);
	i = 0;
	actual = first;
	while (i < counter)
	{
		result[i++] = actual->data;
		actual = actual->next;
	}
	result[i] = 0;
	return (result);
}
