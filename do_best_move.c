/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:37:01 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 08:25:09 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab	moves_in_a(t_stacks *stacks)
{
	t_tab	re;
	int		i;
	int		p;

	i = stacks->stack_b.index;
	re.len = stacks->stack_b.len - i;
	re.tab = (int *)malloc(re.len * sizeof(int));
	if (!re.tab)
		exit(0);
	while (i < stacks->stack_b.len)
	{
		p = nb_position(stacks, stacks->stack_b.tab[i]);
		if (p < (stacks->stack_a.len - stacks->stack_a.index) / 2 + 1)
			re.tab[i - stacks->stack_b.index] = p;
		else
			re.tab[i - stacks->stack_b.index]
				= -(stacks->stack_a.len - stacks->stack_a.index - p);
		i++;
	}
	return (re);
}

t_tab	moves_in_b(t_stacks *stacks)
{
	t_tab	re;
	int		i;

	i = stacks->stack_b.index;
	re.len = stacks->stack_b.len - i;
	re.tab = (int *)malloc(re.len * sizeof(int));
	if (!re.tab)
		exit(0);
	while (i < stacks->stack_b.len)
	{
		if ((i - stacks->stack_b.index) < ((stacks->stack_b.len
					- stacks->stack_b.index) / 2 + 1))
			re.tab[i - stacks->stack_b.index] = i - stacks->stack_b.index;
		else
			re.tab[i - stacks->stack_b.index] = -(stacks->stack_b.len - i);
		i++;
	}
	return (re);
}

t_tab	total_moves(t_stacks *stacks)
{
	t_tab	moves;
	t_tab	a_moves;
	t_tab	b_moves;
	int		i;

	i = 0;
	a_moves = moves_in_a(stacks);
	b_moves = moves_in_b(stacks);
	moves.len = stacks->stack_b.len - stacks->stack_b.index;
	moves.tab = (int *)malloc(moves.len * sizeof(int));
	if (!moves.tab)
		exit(0);
	while (i < moves.len)
	{
		if (a_moves.tab[i] > 0 && b_moves.tab[i] > 0)
			moves.tab[i] = ft_larger_nb(a_moves.tab[i], b_moves.tab[i]) + 1;
		else if (a_moves.tab[i] < 0 && b_moves.tab[i] < 0)
			moves.tab[i] = ft_larger_nb(ft_abs_value(a_moves.tab[i]),
					ft_abs_value(b_moves.tab[i])) + 1;
		else
			moves.tab[i] = ft_abs_value(a_moves.tab[i])
				+ ft_abs_value(b_moves.tab[i]) + 1;
		i++;
	}
	return (free(a_moves.tab), free(b_moves.tab), moves);
}

static void	util(int *i, int *min, int *min_i, t_tab *tab)
{
	while (*i < tab->len)
	{
		if (*min > tab->tab[*i])
		{
			*min = tab->tab[*i];
			*min_i = *i;
		}
		*i += 1;
	}
}

void	do_best_move(t_stacks *stacks)
{
	t_tab	tab;
	t_moves	moves;
	int		i;
	int		min;
	int		min_i;

	tab = total_moves(stacks);
	i = 0;
	min = tab.tab[i];
	min_i = 0;
	util(&i, &min, &min_i, &tab);
	free(tab.tab);
	if (min_i < tab.len / 2 + 1)
		moves.moves_b = min_i;
	else
		moves.moves_b = -(tab.len - min_i);
	i = nb_position(stacks, stacks->stack_b.tab[min_i + stacks->stack_b.index]);
	if (i < (stacks->stack_a.len - stacks->stack_a.index) / 2 + 1)
		moves.moves_a = i;
	else
		moves.moves_a = -(stacks->stack_a.len - stacks->stack_a.index - i);
	push_a(stacks, moves);
}
