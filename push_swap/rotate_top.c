/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:41 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/01 18:12:04 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_top(t_list **stack_a, int index)
{
	int	s_size;
	int	reverse;

	s_size = ft_lstsize(*stack_a);
	if (index <= s_size / 2)
	{
		while (index > 0)
		{
			ra(stack_a, 1);
			index--;
		}
	}
	else
	{
		reverse = s_size - index;
		while (reverse > 0)
		{
			rra(stack_a, 1);
			reverse--;
		}
	}
}

void	rotate_b_to_top(t_list **stack_b, int target)
{
	int	s_size;
	int	reverse;

	s_size = ft_lstsize(*stack_b);
	if (target <= s_size / 2)
	{
		while (target > 0)
		{
			rb(stack_b, 1);
			target--;
		}
	}
	else
	{
		reverse = s_size - target;
		while (reverse > 0)
		{
			rrb(stack_b, 1);
			reverse--;
		}
	}
}

static void	rotate_both_up(t_list **stack_a, t_list **stack_b,
	int index, int target)

{
	while (target > 0 && index > 0)
	{
		rr(stack_a, stack_b);
		target--;
		index--;
	}
	while (target-- > 0)
		rb(stack_b, 1);
	while (index-- > 0)
		ra(stack_a, 1);
}

static void	rotate_both_down(t_list **stack_a, t_list **stack_b,
	int reverse, int reverse2)
{
	while (reverse > 0 && reverse2 > 0)
	{
		rrr(stack_a, stack_b);
		reverse--;
		reverse2--;
	}
	while (reverse-- > 0)
		rra(stack_a, 1);
	while (reverse2-- > 0)
		rrb(stack_b, 1);
}

void	rotate_mixed(t_list **stack_a, t_list **stack_b,
	int index, int target)
{
	int	s_size;
	int	s_size2;
	int	reverse;
	int	reverse2;

	s_size = ft_lstsize(*stack_a);
	s_size2 = ft_lstsize(*stack_b);
	reverse = s_size - index;
	reverse2 = s_size2 - target;
	if ((index <= s_size / 2) && (target <= s_size2 / 2))
		rotate_both_up(stack_a, stack_b, index, target);
	else if ((index > s_size / 2) && (target > s_size2 / 2))
		rotate_both_down(stack_a, stack_b, reverse, reverse2);
	else
	{
		rotate_a_to_top(stack_a, index);
		rotate_b_to_top(stack_b, target);
	}
}
