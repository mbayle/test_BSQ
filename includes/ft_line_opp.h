/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:16:05 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 10:26:19 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINE_OPP_H
# define FT_LINE_OPP_H
# include <stdlib.h>
# include "ft_node_opp.h"
# include "ft_memory_opp.h"
# include "libft.h"

typedef struct	s_bigdata
{
	char	e;
	char	w;
	char	s;
	int		y;
	int		x;
}				t_bigdata;
t_bigdata		*ft_line_info(int fb);
char			*ft_unknow_line(int fb, t_bigdata *data);
char			*ft_know_line(int fb, t_bigdata *data);
char			**ft_matrix(int fb, t_bigdata **data);
#endif
