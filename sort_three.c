/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:16:09 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/10 08:22:03 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	if (stacks->stack_a.tab[0] > stacks->stack_a.tab[1])
		sa(stacks, 1);
	if (stacks->stack_a.tab[1] > stacks->stack_a.tab[2])
		rra(stacks, 1);
	if (stacks->stack_a.tab[0] > stacks->stack_a.tab[1])
		sa(stacks, 1);
	exit(0);
}
