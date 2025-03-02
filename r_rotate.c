/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:59 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/02 15:30:10 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **lst)
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
	if (last)
		last->next = NULL;
	first = temp;
	first->next = *lst;
	*lst = first;
}
