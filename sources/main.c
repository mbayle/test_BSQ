/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:15:12 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 17:57:10 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_line_opp.h"
#include "ft_memory_opp.h"

int	main(int argc, char **argv)
{
	t_bigdata	*data;
	char		*lineone;

	(void)argc;
	(void)argv;
	if ((data = ft_line_info(0)) == 0)
		return (1);
	ft_putnbr(data->y);
	ft_putchar(data->e);
	ft_putchar(data->w);
	ft_putchar(data->s);
	ft_putchar('\n');
	if ((lineone = ft_unknow_line(0, data)) == 0)
	{
		free(data);
		return (1);
	}
	ft_putstr(lineone);
	ft_putchar('\n');
	free(lineone);
	free(data);
	return (0);
}
