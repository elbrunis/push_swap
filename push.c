/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:33 by biniesta          #+#    #+#             */
/*   Updated: 2025/02/28 16:04:09 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **push, t_list **pull)
{
	t_list *temp;

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