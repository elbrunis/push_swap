/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:27:27 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/04 12:45:05 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// IMPORTANTE: Hay que seguir el orden de preferencia para que se ejecute bien
int	num_of_numbers(t_list *lst) // la que primero se ejecuta
{
	int num;

	num = 0;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}

static int	biggest_int(t_list *lst) // la segunda que se ejecuta
{
	int biggest;

	biggest = INT_MIN;
	while (lst)
	{
		if (lst->data > biggest)
			biggest = lst->data;
		lst = lst->next;
	}
	return (biggest);
}

int	biggest_bits(t_list *lst) // la tercera que se ejecuta
{
	int biggest;
	int bits;
	
	biggest = biggest_int(lst);
	bits = 0;
	while (biggest)
	{
		biggest = biggest >> 1;
		bits++;
	}
	return (bits);
}