/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:26:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/05 20:13:43 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check one digit
static int is_digit(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] == '-' || str[i] == '+') && sign == 0)
		{
			sign = 1;
			i++;
		}
		if (!str[i])
			return (1);
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	return (0);
}

static int	check_int(char *str, t_info *info)
{
	int num;

	num = ft_atoi(str);
	if (ft_atol(str) != num) //vrango int min y el int max
		return (1);
	if (num > info->biggest)
		info->biggest = num;
	if (num < info->smallest)
		info->smallest = num;
	return (0);
}

static int	check_list(t_info *info)
{
	int	i;

	i = 0;
	while (info->list[i]) // verificacion de el int min
	{
		if(is_digit(info->list[i]))
		{
			free_array(info->list);
			ft_error("invalid input", NULL, NULL);
		}
		if (check_int(info->list[i], info))
		{
			free_array(info->list);
			ft_error("INT_MIN", NULL, NULL);
		}
		get_number(info, info->list[i]);
		i++;
	}
	free_array(info->list);
	return (0);
}

static int	check_array(t_info *info)
{
	free_array(info->list);
	if (is_digit(info->str))
	{
		free(info->str);
		ft_error("invalid input", NULL, NULL);
	}
	if (check_int(info->str, info))
	{
		free(info->str);
		ft_error("INT_MIN", NULL, NULL);
	}
	get_number(info, info->str);	
	return (0);
}

int	check_argv(int argc, char **argv, t_info *info)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		info->str = ft_strdup(argv[i++]);// extraemos el argumento
		if (!info->str)
			ft_error("memory null", NULL, NULL);
		info->list = ft_split(info->str, ' ');
		if(!info->list[1]) // verificamos si es una string
			check_array(info);
		else
			check_list(info);
		free(info->str);
	}
	return (0);
}
