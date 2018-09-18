/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 04:40:14 by clboutry          #+#    #+#             */
/*   Updated: 2018/09/18 04:41:27 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_replace_square(int MON_TABLEAU, int x_max_position, int y_max_position, int sizemax)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < sizemax)
	{
		while (i < sizemax)
		{
			tab[y_max_position][x_max_position] = MON_SIGNE_POUR_LES_SQUARES;
			x_max_position++;
			i++;

		}
		x_max_position -= i;
		i = 0;
		y_max_position++;
		j++;
	}
	return (MONTABLEAU)
}

