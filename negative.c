/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:15:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/06 16:03:46 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// static void	print_list2(t_list *a)
// {
// 	int i = 0;
// 	while (a)
// 	{
// 		printf("%ld ", a->id);
// 		if (i == 30)
// 		{
// 			ft_printf("\n");
// 			i = 0;
// 		}
// 		a = a->next;
// 	}
// 	ft_printf("\n");
// }

void	convert_negative(t_info *info)
{
	long int	diff;
	t_list		*temp;

	if (info->smallest >= 0)
		return ;
	diff =  info->smallest * -1;
	temp = info->node;
	while (temp)
	{
		temp->id = temp->data;
		temp->data = diff +  temp->data;
		temp = temp->next;
	}
}
