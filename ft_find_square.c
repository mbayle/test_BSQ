/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:51:29 by clboutry          #+#    #+#             */
/*   Updated: 2018/09/18 03:43:10 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tableau(int tab[4][13], t_bigdata *data)
{
	int x_max_pos;
	int y_max_pos;
	int sizemax;
	int x_depart;
	int y_depat;
	int x_actu;
	int y_actu;
	int xmax_tab = data->x;
	int ymax_tab = data->y;
	int size;

	sizemax = 0;
	x_depart = 0;
	y_depart = 0;
	x_actu = 0;
	y_actu = 0;
	size = 0;
	while (y_depart < (ymax_tab - sizemax))
	{
		while (x_depart < (xmax_tab - sizemax))
		{
			while (x_actu < (x_depart + size) && tab[y_actu][x_actu] != 1
					&& x_actu < xmax_tab)
				x_actu++;
			while (y_actu < (y_depart + size) && tab[y_actu][x_actu] != 1
					&& y_actu < ymax_tab)
				y_actu++;
			while (x_actu > x_depart && tab[y_actu][x_actu] != 1
					&& x_actu < xmax_tab)
				x_actu--;
			if (size > sizemax)
			{
				x_max_pos = x_depart;
				y_max_pos = y_depart;
				sizemax = size;
			}
			if (tab[y_actu][x_actu] != 1 && y_actu < ymax_tab
					&& x_actu < xmax_tab)
			{
				x_actu = x_depart + size;
				y_actu = y_depart;
				size++;
			}
			else
			{
				x_depart++;
				x_actu = x_depart;
				y_actu = y_depart;
				size = 0;
			}
		}
		x_depart = 0;
		y_depart++;
		size = 0;
	}
	printf("%d\n %d\n %d\n", x_max_pos, y_max_pos, sizemax);
	return (x_max_pos, y_max_pos, sizemax);
}
