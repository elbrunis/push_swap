/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:59 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/07 18:45:05 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*first;
	t_list	*last;

	if (!*lst || !(*lst)->next)
	{
		write(1, "Error3\n", 7);
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	if (last != NULL)
		last->next = NULL;
	first = temp;
	first->next = *lst;
	*lst = first;
}

void	r_rotate_a(t_list **a)
{
	r_rotate(a);
	write(1, "ra\n", 3);
}

void	r_rotate_b(t_list **b)
{
	r_rotate(b);
	write(1, "rb\n", 3);
}

void	r_rotate_ab(t_list **a, t_list **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rr\n", 3);
}
