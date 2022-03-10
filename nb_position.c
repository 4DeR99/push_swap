/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:48:47 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 08:24:40 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	util1(int *i, int *m, int *j, t_stacks *stacks)
{
	while (*i < stacks->stack_a.len)
	{
		if (*m > stacks->stack_a.tab[*i])
		{
			*m = stacks->stack_a.tab[*i];
			*j = *i;
		}
		*i += 1;
	}
}

static void	util2(int *i, int *m, int *j, t_stacks *stacks)
{
	while (*i < stacks->stack_a.len)
	{
		if (*m < stacks->stack_a.tab[*i])
		{
			*m = stacks->stack_a.tab[*i];
			*j = *i;
		}
		*i += 1;
	}
}

static void	set(int *j, int *i, int *m, t_stacks *stacks)
{
	*j = 0;
	*i = stacks->stack_a.index;
	*m = stacks->stack_a.tab[*i];
}

int	nb_position(t_stacks *stacks, int nb)
{
	int	i;
	int	j;

	i = stacks->stack_a.index;
	j = stacks->stack_a.len - 1;
	if (nb < stacks->stack_a.tab[i] && nb > stacks->stack_a.tab[j])
		return (0);
	while ((i - stacks->stack_a.index) < ((stacks->stack_a.len
				- stacks->stack_a.index) / 2 + 1))
	{
		if (nb > stacks->stack_a.tab[i] && nb < stacks->stack_a.tab[i + 1])
			return (i + 1 - stacks->stack_a.index);
		if (nb > stacks->stack_a.tab[j - 1] && nb < stacks->stack_a.tab[j])
			return (j - stacks->stack_a.index);
		i++;
		j--;
	}
	set(&j, &i, &stacks->m, stacks);
	if (nb < stacks->m)
	{
		util1(&i, &stacks->m, &j, stacks);
		return (j - stacks->stack_a.index);
	}
	util2(&i, &stacks->m, &j, stacks);
	return (j + 1 - stacks->stack_a.index);
}
