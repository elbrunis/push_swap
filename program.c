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

// void do_moves(t_list **a, t_list **b, char *str)
// {
// 	if(ft_strncmp(str, "sa", 2) == 0)
// 		swap_a(a);
// 	if(ft_strncmp(str, "sb", 2) == 0)
// 		swap_b(b);
// 	if(ft_strncmp(str, "pa", 2) == 0)
// 		push_a(a, b);
// 	if(ft_strncmp(str, "pb", 2) == 0)
// 		push_b(a, b);
// 	if(ft_strncmp(str, "ra", 2) == 0)
// 		rotate_a(a);
// 	if(ft_strncmp(str, "rb", 2) == 0)
// 		rotate_b(b);
// 	if(ft_strncmp(str, "rr", 2) == 0)
// 	{
// 		rotate_ab(a, b);
// 		return ;
// 	}
// 	if(	ft_strncmp(str, "rra", 3) == 0)
// 		r_rotate_a(a);
// 	if(ft_strncmp(str, "rrb", 3) == 0)
// 		r_rotate_b(b);
// 	if(ft_strncmp(str, "rrr", 3) == 0)
// 		r_rotate_ab(a, b);
// }
void free_list(t_list *list)
{
    t_list *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}
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
	print_list(a);
	algorithm(&a, &b);
	print_list(a);
	free_list(a);
	free_list(b);
	return (0);
}