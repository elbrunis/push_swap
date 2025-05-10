/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:15:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/10 12:44:08 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

void	set_id(t_info *info)
{
	t_list	*temp;
	t_list	*biggest;
	int		n_nodes;

	n_nodes = count_nodes(info->node) - 1;
	while (n_nodes >= 0)
	{
		temp = info->node;
		biggest = NULL;
		while (temp)
		{
			if (!temp->id && (biggest == NULL || temp->data > biggest->data))
				biggest = temp;
			temp = temp->next;
		}
		if (biggest)
			biggest->id = n_nodes;
		n_nodes--;
	}
}
