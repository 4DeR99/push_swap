/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:56:05 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/10 08:34:43 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	atol_util(long nbr)
{
	if (nbr > MAX_INT || nbr < MIN_INT)
	{
		write(2, "Error\n", slen("Error\n"));
		exit(0);
	}
}

int	ft_atol(const char *s)
{
	long	nbr;
	int		n;
	int		i;

	n = 1;
	nbr = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			n *= -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	atol_util(nbr * n);
	return (nbr * n);
}
