/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:42 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/10 18:00:05 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_info	*init_struct(void)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (NULL);
	new->biggest = INT_MIN;
	new->smallest = INT_MAX;
	new->str = NULL;
	new->list = NULL;
	new->node = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_info	*info;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	info = init_struct();
	if (!info)
		ft_error(NULL, NULL);
	check_argv(argc, argv, info);
	a = info->node;
	if (is_sorted(a))
		ft_error(info, NULL);
	set_id(info);
	algorithm(&a, &b);
	info->node = a;
	free_info(info);
	free_list(b);
	return (0);
}
