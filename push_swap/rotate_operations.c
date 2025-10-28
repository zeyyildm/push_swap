/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:12 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/28 19:32:13 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int flag)
{
	t_list	*head;

	head = (*stack_a);
	pop(stack_a);
	ft_lstadd_back(stack_a, head);
	if(flag)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b,int flag)
{
	t_list	*head;

	head = (*stack_b);
	pop(stack_b);
	ft_lstadd_back(stack_b, head);
	if(flag)
		write(1, "rb\n", 3);
}
