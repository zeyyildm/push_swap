/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:22:28 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/31 19:11:20 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_atol(char *storage, char **tmp, long *n)
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

static char	*concat_args(char **av)
{
	char	*storage;
	char	*tmp;
	int		i;

	storage = ft_strdup("");
	i = 1;
	while (av[i])
	{
		tmp = storage;
		storage = ft_strjoin2(storage, av[i]);
		free(tmp);
		i++;
	}
	return (storage);
}

static void	parser(char **tmp, long *rt, char *storage)
{
	int	i;

	i = -1;

	while (tmp[++i])
	{
		rt[i] = ft_atol(tmp[i]);
		if (rt[i] == -2147483648)
		{
			write(1, "Error\n", 6);
			free_atol(storage, tmp, rt);
			exit(1);
		}
	}
}

long	*parse_input(char **av, int *count)
{
	char	*storage;
	char	**tmp;
	long	*rt;
	int		i;

	storage = concat_args(av);
	tmp = ft_split(storage, ' ');
	if (!tmp)
		exit(1);
	i = 0;
	while (tmp[i])
		i++;
	*count = i;
	rt = malloc(i * sizeof(long));
	if (!rt)
		exit(1);
	parser(tmp, rt, storage);
	is_duplicate(rt, *count, tmp, storage);
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	free(storage);
	return (rt);
}

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
