/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:52:25 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/31 18:25:25 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return;
	while (*stack)
	{
		tmp = (*stack)->next;  // sıradaki düğümü sakla
		free(*stack);          // şu anki düğümü serbest bırak
		*stack = tmp;          // sıradaki düğüme geç
	}
	free(stack);           // güvenlik: pointer’ı sıfırla
}
