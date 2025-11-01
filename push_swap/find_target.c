/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:19:06 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/01 18:11:32 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_or_min_target(t_list **stack, int val)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->data == val)
			return (temp->index);
		temp = temp->next;
	}
	return (0);
}

static int	find_bigger_target(t_list **stack_b, int data)
{
	t_list	*temp;
	int		bigger;
	int		target;

	temp = *stack_b;
	bigger = INT_MIN;
	target = 0;
	while (temp)
	{
		if (temp->data < data && temp->data > bigger)
		{
			bigger = temp->data;
			target = temp->index;
		}
		temp = temp->next;
	}
	return (target);
}

void	find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	int		max_val;
	int		min_val;

	temp_a = *stack_a;
	max_val = find_max(stack_b);
	min_val = find_min(stack_b);
	while (temp_a)
	{
		if (temp_a->data > max_val || temp_a->data < min_val)
			temp_a->target = find_max_or_min_target(stack_b, max_val);
		else
			temp_a->target = find_bigger_target(stack_b, temp_a->data);
		temp_a = temp_a->next;
	}
}

static int	find_smaller_target_a(t_list **stack_a, int data)
{
	t_list	*temp;
	int		smaller;
	int		target;

	temp = *stack_a;
	smaller = INT_MAX;
	target = 0;
	while (temp)
	{
		if (data < temp->data && temp->data < smaller)
		{
			smaller = temp->data;
			target = temp->index;
		}
		temp = temp->next;
	}
	return (target);
}

void	find_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	int		max_val;
	int		min_val;

	temp_b = *stack_b;
	max_val = find_max(stack_a);
	min_val = find_min(stack_a);
	while (temp_b)
	{
		if (temp_b->data > max_val || temp_b->data < min_val)
			temp_b->target = find_max_or_min_target(stack_a, min_val);
		else
			temp_b->target = find_smaller_target_a(stack_a, temp_b->data);
		temp_b = temp_b->next;
	}
}
