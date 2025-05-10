/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:24:10 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/09 13:16:27 by biniesta         ###   ########.fr       */
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

static void sort_three(t_list **a)
{
	int biggest;

	biggest = biggest_int(*a);
	if ((*a)->id == biggest)
		rotate_a(a);
	else if ((*a)->next->id == biggest)
		r_rotate_a(a);
	if ((*a)->id > (*a)->next->id)
		swap_a(a);
}

static void	sort_five(t_list **a, t_list **b)
{
	int	n_nodes;
	int	i;

	n_nodes = count_nodes(*a);
	i = 0;
	while (n_nodes--)
	{
		if ((*a)->id == 0 ||(*a)->id == 1)
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
		if (i == 2)
			break ;
	}
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
	if ((*a)->id > (*a)->next->id)
		swap_a(a);
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
			if (((*a)->id >> i) & 1)
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
		if(is_sorted(*a))
		break ;
		i++;
	}
	ft_printf("moves: %d\n", moves);
}

void	algorithm(t_list **a, t_list **b)
{
	int	n_nodes;

	n_nodes = count_nodes(*a);
	if (n_nodes > 5)
		radix_sort(a, b, num_of_numbers(*a), biggest_bits(*a));
	else if (n_nodes == 5 || 4 == n_nodes)
		sort_five(a, b);
	else if (n_nodes == 3)
		sort_three(a);
	else if (n_nodes == 2)
	{
		if ((*a)->id > (*a)->next->id)
			swap_a(a);
	}
}