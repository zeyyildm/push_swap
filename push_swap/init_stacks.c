/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:24:25 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/01 18:11:39 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**init_stack_a(long *rt, int count)
{
	t_list	**stack_a;
	t_list	*node;
	int		i;

	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		exit(1);
	*stack_a = NULL;
	i = 0;
	while (i < count)
	{
		node = ft_lstnew(rt[i]);
		ft_lstadd_back(stack_a, node);
		i++;
	}
	return (stack_a);
}

t_list	**init_stack_b(void)
{
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		exit(1);
	*stack_b = NULL;
	return (stack_b);
}
