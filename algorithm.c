/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:24:10 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/04 17:29:17 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_list **a, t_list **b, int n_num, int n_bits)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("n_num: %d\n", n_num);
	ft_printf("n_bits: %d\n", n_bits);
	while (i < n_bits)
	{
		j = 0;
		while (j < n_num) // puede haber algo aqui
		{
			if (((*a)->data >> i) & 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while(*b)
			push_a(a, b);
		// if (i == 3)
		// 	print_list(*a);
		// 	exit(0);
		i++;
	}
}

void	algorithm(t_list **a, t_list **b)
{
	if (a)
		radix_sort(a, b, num_of_numbers(*a), biggest_bits(*a));
}

// void algorithm(t_list **a, t_list **b)
// {
//     if (a && *a)
//     {
//         int n_num = num_of_numbers(*a);
//         int n_bits = biggest_bits(*a);
//         radix_sort(a, b, n_num, n_bits);
//     }
// }