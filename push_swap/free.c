/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:52:25 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/31 19:06:49 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}
int null_check(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if(av[i][0]=='\0')
		{
			write(1,"Error\n",6);
			return 1;
		}
		i++;
	}
	return 0;
}