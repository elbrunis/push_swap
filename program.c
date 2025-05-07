/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:42 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/06 16:05:23 by biniesta         ###   ########.fr       */
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
	{
		write(1, "Error\n", 6);
		return (0);
	}
	info = init_struct();
	if (!info)
		return (1);
	// free(info);
	check_argv(argc, argv, info);
	// create_list(&a, argc, argv);
	a = info->node;
	if (is_sorted(a))
		ft_error("stack is sorted", a, NULL);
	convert_negative(info);
	algorithm(&a, &b);
	print_list(info, a);
	free_list(a);
	free_list(b);
	return (0);
}
