/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:56:50 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/01 18:11:48 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_duplicate(char *storage, char **tmp, long *n)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
	if (storage)
		free(storage);
	if (n)
		free(n);
}

void	is_duplicate(long *n, int counter, char **tmp, char *storage)
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
				free_duplicate(storage, tmp, n);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
