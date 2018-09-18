/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:15:12 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/18 09:45:06 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char **argv)
{
	int i;
	int fb;

	if (argc == 1)
		ft_do_this_fb(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fb = open(argv[i], O_RDONLY);
			ft_do_this_fb(fb);
			ft_putchar((i + 1 < argc) ? '\n' : '\0');
			close(fb);
			i++;
		}
	}
}

void	ft_do_this_fb(int fb)
{
	t_bigdata	*data;
	char		**matris;
	t_fulldata	*r;

	data = 0;
	if ((matris = ft_matrix(fb, &data)) == 0)
	{
		free(data);
		write(2, "map error\n", 10);
		return ;
	}
	if ((r = ft_find(matris, data)) == 0)
	{
		free(data);
		free(matris);
		return ;
	}
	ft_fill_square(matris, data, r);
	ft_display_matris(matris, data->x, data->y);
	ft_free_matris(matris, data->y);
	free(data);
	free(r);
}
