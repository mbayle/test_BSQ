/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabettin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 22:26:23 by gabettin          #+#    #+#             */
/*   Updated: 2018/09/11 22:49:52 by gabettin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi					(char *str);
void	ft_putchar				(char c);
void	ft_putstr				(char *str);
void	ft_putnbr				(int nbr);
char	**ft_split_whitespaces	(char *str);
char	*ft_strcat				(char *s1, char *s2);
int		ft_strcmp				(char *s1, char *s2);
char	*ft_strcpy				(char *dest, char *src);
char	*ft_strdup				(char *str);
char	*ft_strncat				(char *s1, char *s2, unsigned int n);
char	*ft_strncpy				(char *dest, char *src, unsigned int n);
char	*ft_strstr				(char *str, char *to_find);
void	ft_swap					(void *a, void *b);
#endif
