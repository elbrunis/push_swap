/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:27:27 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/03 19:18:29 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// IMPORTANTE: Hay que seguir el orden de preferencia para que se ejecute bien
int	num_of_numbers(t_list **lst) // la que primero se ejecuta
{
	t_list *temp;
	int num;

	temp = *lst;
	num = 0;
	while (temp)
	{
		if ((temp->data >= INT_MIN) && (temp->data <= INT_MAX))
			num++;
		else
			ft_error("Hay un numero no valido"); // finish the program
		temp = temp->next;
	}
	return (num);
}

int	bigguest_int(t_list **lst) // la segunda que se ejecuta
{
	t_list	*temp;
	int		bigguest;

	temp = *lst;
	bigguest = INT_MIN;
	while (temp)
	{
		if (temp->data > bigguest)
			bigguest = temp->data;
		else
			ft_error("numero muy pequeño");
		temp = temp->next;
	}
	return (bigguest);
}

int	bigguest_bits(int bigguest) // la tercera que se ejecuta
{
	int bits;

	bits = 0;
	while (bigguest)
	{
		bigguest = bigguest >> 1;
		bits++;
	}
	return (bits);
}