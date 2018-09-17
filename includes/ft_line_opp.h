/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_opp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:16:05 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 16:31:31 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINE_OPP_H
# define FT_LINE_OPP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_bigdata
{
	char	E;
	char	W;
	char	S;
	int		Y;
	int		X;
}				t_bigdata;
t_bigdata	*ft_line_info(int fb);
#endif
