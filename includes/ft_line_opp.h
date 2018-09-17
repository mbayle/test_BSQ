/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:16:05 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 17:14:46 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINE_OPP_H
# define FT_LINE_OPP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_bigdata
{
	char	e;
	char	w;
	char	s;
	int		y;
	int		x;
}				t_bigdata;
t_bigdata		*ft_line_info(int fb);
#endif
