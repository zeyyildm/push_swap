/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:00:05 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/01 18:11:55 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (size == 3)
		sort_a_end(stack_a);
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheaper;

	push_top_two(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		find_index(stack_a, stack_b);
		find_target(stack_a, stack_b);
		total_cost(stack_a, stack_b);
		cheaper = find_cheaper(stack_a);
		rotate_mixed(stack_a, stack_b,
			cheaper->index, cheaper->target);
		pb(stack_b, stack_a);
	}
	sort_a_end(stack_a);
	push_back_to_a(stack_a, stack_b);
}

void	final_rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*end_value;
	int		min_index;

	find_index(stack_a, stack_b);
	end_value = *stack_a;
	min_index = 0;
	while (end_value)
	{
		if (find_min(stack_a) == end_value->data)
			min_index = end_value->index;
		end_value = end_value->next;
	}
	rotate_a_to_top(stack_a, min_index);
}

int	is_sorted(long *rt, int count)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < count - 1)
	{
		if (rt[i] > rt[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	long	*rt;
	int		count;

	if (ac < 2 || null_check(av))
		return (0);
	rt = parse_input(av, &count);
	if (is_sorted(rt, count))
		return (free(rt), 0);
	stack_a = init_stack_a(rt, count);
	stack_b = init_stack_b();
	if (ft_lstsize(*stack_a) <= 3)
	{
		sort_small(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
		return (free(rt), 0);
	}
	sort_large(stack_a, stack_b);
	final_rotate(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (free(rt), 0);
}
