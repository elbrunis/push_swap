/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:15:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/07 15:55:43 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	convert_negative(t_info *info)
// {
// 	long int	diff;
// 	t_list		*temp;

// 	if (info->smallest >= 0)
// 		return ;
// 	diff =  info->smallest * -1;
// 	temp = info->node;
// 	while (temp)
// 	{
// 		temp->id = temp->data;
// 		temp->data = diff +  temp->data;
// 		temp = temp->next;
// 	}
// }
static int count_nodes(t_list *list)
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

	n_nodes = count_nodes(info->node);
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
