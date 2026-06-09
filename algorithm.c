/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:24:10 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/28 14:42:07 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	radix_sort(t_list **a, t_list **b, int n_num, int n_bits)
{
	int	i;
	int	j;
	int moves;

	i = 0;
	j = 0;
	moves = 0;
	while (i < n_bits)
	{
		j = 0;
		while (j < n_num && !is_sorted(*a))
		{
			if (((*a)->data >> i) & 1)
			{
				rotate_a(a);
				moves++;
			}
			else
			{
				push_b(a, b);
				moves++;
			}
			j++;
		}
		while(*b)
		{
			push_a(a, b);
			moves++;
		}
		i++;
	}
	ft_printf("moves: %d\n", moves);
}

void	algorithm(t_list **a, t_list **b)
{
	if (a)
		radix_sort(a, b, num_of_numbers(*a), biggest_bits(*a));
}