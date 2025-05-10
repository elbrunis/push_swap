/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:57:51 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/10 15:43:33 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
	{
		write(1, "Error1\n", 7);
		return ;
	}
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	swap_a(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
