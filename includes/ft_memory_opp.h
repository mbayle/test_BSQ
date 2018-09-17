/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_opp.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 04:26:07 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 16:18:51 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_OPP_H
# define FT_MEMORY_OPP_H
# include "ft_node_opp.h"
# include <stdlib.h>

void	*ft_free_node_chain(t_node *first);
void	*ft_free_dnode_chain(t_dnode *first);
void	*ft_free_matris(char **array);
void	*ft_free_simple(void* object);
#endif
