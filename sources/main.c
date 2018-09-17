/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:15:12 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 00:14:59 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_line_opp.h"
#include "ft_memory_opp.h"
#include "ft_display.h"

int	main(int argc, char **argv)
{
	t_bigdata	*data;
	char		**matrix;

	(void)argc;
	(void)argv;
	data = 0;
	if ((matrix = ft_matrix(0, &data)) == 0)
	{
		free(data);
		write(2, "map error\n", 1);
	}
	ft_display_matris(matrix, data->x, data->y);
	for (int i = 0; i < data->y; i++)
		free(matrix[i]);
	free(matrix);
	while(1);
	return (0);
}
