/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:33 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/03 13:35:49 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_list **push, t_list **pull)
{
	t_list	*temp;

	if (!push || !*push)
	{
		write(1, "Error0\n", 7);
		return ;
	}
	temp = (*push)->next;
	(*push)->next = *pull;
	*pull = *push;
	*push = temp;
}

void	push_a(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
