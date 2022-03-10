/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:09:38 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:54:39 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_a.len - 1;
	tmp = stacks->stack_a.tab[index];
	while (index > stacks->stack_a.index)
	{
		stacks->stack_a.tab[index] = stacks->stack_a.tab[index - 1];
		index--;
	}
	stacks->stack_a.tab[index] = tmp;
	index = stacks->stack_b.len - 1;
	tmp = stacks->stack_b.tab[index];
	while (index > stacks->stack_b.index)
	{
		stacks->stack_b.tab[index] = stacks->stack_b.tab[index - 1];
		index--;
	}
	stacks->stack_b.tab[index] = tmp;
	if (i)
		write(1, "rrr\n", 4);
}
