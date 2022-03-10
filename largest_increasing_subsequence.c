/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:51:05 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 19:07:57 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increasing_lis_util(int *test, int *lis_n, int next)
{
	if (*test < next)
	{
		*lis_n = *lis_n + 1;
		*test = next;
	}
}

void	increasing_lis(int *tab, int len, t_lis *lis)
{
	int	i;
	int	j;
	int	lis_n;
	int	test;

	i = 0;
	lis->lis1 = (int *)malloc(len * sizeof(int));
	if (!lis->lis1)
		exit(0);
	while (i < len)
	{
		lis_n = 1;
		test = tab[i];
		j = i + 1;
		if (j == len)
			j = 0;
		while (j != i)
		{
			increasing_lis_util(&test, &lis_n, tab[j++]);
			if (j == len)
				j = 0;
		}
		lis->lis1[i++] = lis_n;
	}
}

void	decreasing_lis_util(int *test, int *lis_n, int next)
{
	if (*test > next)
	{
		*lis_n = *lis_n + 1;
		*test = next;
	}
}

void	decreasing_lis(int *tab, int len, t_lis *lis)
{
	int	i;
	int	j;
	int	lis_n;
	int	test;

	i = len - 1;
	lis->lis2 = (int *)malloc(len * sizeof(int));
	if (!lis->lis2)
		exit(0);
	while (i > 0)
	{
		lis_n = 1;
		test = tab[i];
		j = i - 1;
		if (j == -1)
			j = len - 1;
		while (j != i)
		{
			decreasing_lis_util(&test, &lis_n, tab[j--]);
			if (j == -1)
				j = len - 1;
		}
		lis->lis2[i--] = lis_n;
	}
}

t_tab	largest_increasing_sequence(int *tab, int len)
{
	t_lis	lis_t;
	t_tab	lis;

	increasing_lis(tab, len, &lis_t);
	decreasing_lis(tab, len, &lis_t);
	lis = get_lis(lis_t, tab, len);
	return (lis);
}
