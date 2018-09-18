/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:00:42 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 04:30:03 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SQUARE_H
# define FT_FIND_SQUARE_H
# include "ft_line_opp.h"

typedef struct	s_fulldata
{
	int x_max_pos;
	int y_max_pos;
	int sizemax;
	int x_depart;
	int y_depart;
	int x_actu;
	int y_actu;
	int size;
}				t_fulldata;
t_fulldata		*ft_find(char **tab, t_bigdata *data);
void			ft_find_ext(char **tab, t_bigdata *data, t_fulldata *r);
t_fulldata		*ft_fulldata_init(void);
#endif
