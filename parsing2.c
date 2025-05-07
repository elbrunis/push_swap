/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:56:39 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/06 13:26:56 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dupp(t_list *list, int num)
{
	while (list)
	{
		if (list->data == num)
			return (1);
		list = list->next;
	}
	return (0);
}

static t_list	*new_node(int num)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = num;
	new->id = 0;
	new->next = NULL;
	return (new);
}

void	get_number(t_info *info, char *str)
{
	t_list *temp;

	if (is_dupp(info->node, ft_atoi(str)))
		ft_error("is_dup", NULL, NULL);
	if (!info->node)
		info->node = new_node(ft_atoi(str));
	else
	{
		temp = info->node;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node(ft_atoi(str));
	}
}