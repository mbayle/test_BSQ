/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 02:15:12 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/17 16:31:45 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_line_opp.h"
#include "ft_memory_opp.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_bigdata *data;
   
	if ((data = ft_line_info(0)) == 0)
		return (0);
	ft_putnbr(data->X);
	ft_putchar(data->E);
	ft_putchar(data->W);
	ft_putchar(data->S);
	ft_putchar('\n');
	ft_free_simple(data);
}
