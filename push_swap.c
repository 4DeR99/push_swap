/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:30:09 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/10 08:16:03 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_tab		lis;

	if (ac == 1)
	{
		write(2, "------------PUSH_SWAP-----------\n",
			slen("------------PUSH_SWAP-----------\n"));
		write(2, "HOW TO : ./push_swap + -NUMBERS-\n",
			slen("HOW TO : ./push_swap + -NUMBERS-\n"));
		exit(0);
	}
	configure(&stacks, av);
	check_order(&stacks);
	if (stacks.stack_a.len == 3)
		sort_three(&stacks);
	lis = largest_increasing_sequence(stacks.stack_a.tab, stacks.stack_a.len);
	push_to_b(&stacks, lis);
	free(lis.tab);
	while (stacks.stack_b.index != stacks.stack_b.len)
		do_best_move(&stacks);
	rotate_to_finish(&stacks);
	free(stacks.stack_a.tab);
	free(stacks.stack_b.tab);
	return (0);
}
