/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:32:25 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:56:27 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stacks *stacks, t_tab lis)
{
	int	i;
	int	j;
	int	push_b;

	i = stacks->stack_a.index;
	while (i < stacks->stack_a.len)
	{
		push_b = 0;
		j = 0;
		while (j < lis.len)
		{
			if (stacks->stack_a.tab[stacks->stack_a.index] == lis.tab[j])
				break ;
			else if (j == lis.len - 1)
			{
				pb(stacks, 1);
				push_b = 1;
			}
			j++;
		}
		if (!push_b)
			ra(stacks, 1);
		i++;
	}
}
