/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_opp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:57:04 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/16 03:55:00 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_OPP_H
# define FT_NODE_OPP_H
# include <stdlib.h>

typedef struct	s_simple_node
{
	char					data;
	struct s_simple_node	*next;
}				t_node;
typedef	struct	s_double_node
{
	char					*data;
	struct s_double_node	*next;
}				t_dnode;
t_node			*ft_new_node(char data);
t_dnode			*ft_new_dnode(char	*data);
char			*ft_node_to_array(t_node	*first);
char			**ft_dnode_to_array(t_dnode	*first);
#endif
