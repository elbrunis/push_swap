/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:27:38 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/02 17:52:44 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **lst)
{
	t_list *temp;
	t_list *first;

	if (!*lst || !(*lst)->next)
	{
		write(1, "Error2\n", 7);
		return ;
	}

	temp = *lst;
	first = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	*lst = (*lst)->next;
	first->next = NULL;
	temp->next = first;
}

void	rotate_a(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
