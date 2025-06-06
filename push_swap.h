/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:22:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/03/04 14:55:18 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

// error
int		ft_error(char *str, t_list *a, t_list *b);
// crea una lista
void	create_list(t_list **list, int argc, char **argv);
// utils para borrar
void	print_list(t_list *a);
// radix sort
void	algorithm(t_list **a, t_list **b);
// utils
int		num_of_numbers(t_list *lst);
int		biggest_bits(t_list *lst);
int 	is_sorted(t_list *a);

// memory
void	free_list(t_list *list);
// swap
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ab(t_list **a, t_list **b);

// push
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

// rotate
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);

// r_rotate
void	r_rotate_a(t_list **a);
void	r_rotate_b(t_list **b);
void	r_rotate_ab(t_list **a, t_list **b);

#endif