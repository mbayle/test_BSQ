/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 02:51:29 by clboutry          #+#    #+#             */
/*   Updated: 2018/09/18 05:20:13 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find_square.h"

t_fulldata	*ft_find(char **tab, t_bigdata *data)
{
	t_fulldata	*r;

	if ((r = ft_fulldata_init()) == 0)
		return (0);
	while (r->y_depart < (data->y - r->sizemax))
	{
		while (r->x_depart < (data->x - r->sizemax))
		{
			while (r->x_actu < (r->x_depart + r->size) &&
					tab[r->y_actu][r->x_actu] != data->w
					&& r->x_actu < data->x)
				r->x_actu++;
			while (r->y_actu < (r->y_depart + r->size)
			&& tab[r->y_actu][r->x_actu] != data->w && r->y_actu < data->y)
				r->y_actu++;
			while (r->x_actu > r->x_depart &&
				tab[r->y_actu][r->x_actu] != data->w && r->x_actu < data->x)
				r->x_actu--;
			ft_find_ext(tab, data, r);
		}
		r->x_depart = 0;
		r->y_depart++;
		r->size = 0;
	}
	return (r);
}

void		ft_find_ext(char **tab, t_bigdata *data, t_fulldata *r)
{
	if (r->size > r->sizemax)
	{
		r->x_max_pos = r->x_depart;
		r->y_max_pos = r->y_depart;
		r->sizemax = r->size;
	}
	if (tab[r->y_actu][r->x_actu] != data->w && r->y_actu < data->y &&
			r->x_actu < data->x)
	{
		r->x_actu = r->x_depart + r->size;
		r->y_actu = r->y_depart;
		r->size++;
	}
	else
	{
		r->x_depart++;
		r->x_actu = r->x_depart;
		r->y_actu = r->y_depart;
		r->size = 0;
	}
}

void		ft_fill_square(char **tab, t_bigdata *data, t_fulldata *r)
{
	int i;
	int j;

	j = 0;
	while (j < r->sizemax)
	{
		i = 0;
		while (i < r->sizemax)
		{
			tab[r->y_max_pos][r->x_max_pos] = data->s;
			r->x_max_pos++;
			i++;
		}
		r->x_max_pos -= i;
		r->y_max_pos++;
		j++;
	}
}

t_fulldata	*ft_fulldata_init(void)
{
	t_fulldata *result;

	if ((result = malloc(sizeof(t_fulldata))) == 0)
		return (0);
	result->x_max_pos = 0;
	result->y_max_pos = 0;
	result->sizemax = 0;
	result->x_depart = 0;
	result->y_depart = 0;
	result->x_actu = 0;
	result->y_actu = 0;
	result->size = 0;
	return (result);
}
