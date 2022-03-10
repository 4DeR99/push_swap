/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:29:22 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/10 08:25:39 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] != '-' && args[i][0] != '+' && (args[i][0] < '0'
			|| args[i][0] > '9'))
		{
			write(2, "Error\n", slen("Error\n"));
			exit(0);
		}
		if (args[i][0] == '-' && (args[i][1] < '0'
			|| args[i][1] > '9'))
		{
			write(2, "Error\n", slen("Error\n"));
			exit(0);
		}
		i++;
	}
}

void	check_double(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j <= len - 1)
		{
			if (tab[i] == tab[j])
			{
				write(2, "Error\n", slen("Error\n"));
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	configure(t_stacks *stacks, char **av)
{
	char	**args;
	int		i;

	args = join_nd_split(av, &stacks->stack_a.len);
	stacks->stack_b.len = stacks->stack_a.len;
	stacks->stack_a.tab = (int *)malloc(stacks->stack_a.len * sizeof(int));
	stacks->stack_b.tab = (int *)malloc(stacks->stack_b.len * sizeof(int));
	if (!stacks->stack_a.tab || !stacks->stack_b.tab)
		exit(0);
	stacks->stack_a.index = 0;
	stacks->stack_b.index = stacks->stack_b.len;
	check_args(args);
	i = 0;
	while (args[i])
	{
		stacks->stack_a.tab[i] = ft_atol(args[i]);
		i++;
	}
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	check_double(stacks->stack_a.tab, stacks->stack_a.len);
}

char	**join_nd_split(char **av, int *len)
{
	char	**re;
	char	*tmp;
	int		i;

	i = 1;
	tmp = 0;
	while (av[i])
		tmp = ft_strjoin(tmp, av[i++]);
	re = ft_split(tmp, ' ');
	*len = 0;
	while (re[*len])
		*len = *len + 1;
	return (re);
}

void	check_order(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.len - 1)
	{
		if (stacks->stack_a.tab[i] > stacks->stack_a.tab[i + 1])
			return ;
		i++;
	}
	exit(0);
}
