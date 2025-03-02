/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:35:42 by biniesta          #+#    #+#             */
/*   Updated: 2025/02/27 13:49:10 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	create_list(&a, argc, argv);
	b = NULL;
	print_list(b);
	return (0);
}