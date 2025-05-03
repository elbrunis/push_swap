/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:37:27 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/02 23:18:59 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*new_node(int argv)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error("malloc failure", NULL, NULL);
	node->data = argv;
	node->next = NULL;
	return (node);
}

void	create_list(t_list **list, int argc, char **argv)
{
	t_list	*temp;
	int		i;

	i = 1; // omite el primer arg = [./programa]
	while (i < argc)
	{
		if (*list == NULL)
		{
			*list = new_node(ft_atoi(argv[i]));
		}
		else
		{
			temp = *list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node(ft_atoi(argv[i]));
		}
		i++;
	}
}
