/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_opp.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:26:07 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 03:40:19 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_OPP_H
# define FT_MEMORY_OPP_H
# include "ft_node_opp.h"
# include <stdlib.h>

void	*ft_free_node_chain(t_node *first);
void	*ft_free_dnode_chain(t_dnode *first, int and_data);
void	*ft_free_matris(char **array, int y);
void	*ft_free_simple(void *object);
void	*ft_free_node_and_dnode(t_node *node, t_dnode *dnode);
#endif
