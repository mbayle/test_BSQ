/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:15:12 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 08:14:50 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_line_opp.h"
#include "ft_memory_opp.h"
#include "ft_display.h"
#include "ft_find_square.h"

int	main(int argc, char **argv)
{
	t_bigdata	*data;
	char		**matrix;
	t_fulldata	*r;

	(void)argc;
	(void)argv;
	data = 0;
	if ((matrix = ft_matrix(0, &data)) == 0)
	{
		free(data);
		write(2, "map error\n", 10);
		return (1);
	}
	if ((r = ft_find(matrix, data)) == 0)
	{
		//todo : free
		return (1);
	}
	ft_fill_square(matrix, data, r);
	ft_display_matris(matrix, data->x ,data->y);
	ft_free_matris(matrix, data->y);
	return (0);
}
