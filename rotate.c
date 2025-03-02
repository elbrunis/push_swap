/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:27:38 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/01 15:08:39 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
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