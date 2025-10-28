/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:56:50 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:10:23 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_duplicate(long *n, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < counter)
	{
		j = i + 1;
		while (j < counter)
		{
			if (n[i] == n[j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
