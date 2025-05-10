/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:27:27 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/08 14:27:19 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	biggest_int(t_list *lst) // la segunda que se ejecuta
{
	int biggest;

	biggest = INT_MIN;
	while (lst)
	{
		if (lst->id > biggest)
			biggest = lst->id;
		lst = lst->next;
	}
	return (biggest);
}

int	biggest_bits(t_list *lst) // la tercera que se ejecuta
{
	int biggest;
	int bits;
	
	biggest = biggest_int(lst);
	bits = 0;
	while (biggest)
	{
		biggest = biggest >> 1;
		bits++;
	}
	return (bits);
}

int	num_of_numbers(t_list *lst) // la que primero se ejecuta
{
	int num;

	num = 0;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}

int	ft_error(char *str, t_list *a, t_list *b)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	// if (!list)
	// 	ft_error("there is no stack to free", NULL, NULL);
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

// para testear
void	print_list(t_list *a)
{
	int i = 0;
	while (a)
	{
		ft_printf("%d ", a->data);
		i++;
		if (i == 30)
		{
			ft_printf("\n");
			i = 0;
		}
		a = a->next;
	}
	ft_printf("\n");
}