/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:42 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/04 15:31:06 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	check_argv(argc, argv);
	create_list(&a, argc, argv);
	if (is_sorted(a))
		ft_error("stack is sorted", a, NULL);
	algorithm(&a, &b);
	print_list(a);
	free_list(a);
	free_list(b);
	return (0);
}
