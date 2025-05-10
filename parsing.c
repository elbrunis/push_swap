/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:26:46 by biniesta          #+#    #+#             */
/*   Updated: 2025/05/10 16:04:04 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char *str)
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
	int	num;
	int	str_len;

	num = ft_atoi(str);
	str_len = ft_strlen(str);
	if (str_len > 17)
		return (1);
	if (ft_atol(str) != num)
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
	while (info->list[i])
	{
		if (is_digit(info->list[i]))
			ft_error(info, NULL);
		if (check_int(info->list[i], info))
			ft_error(info, NULL);
		get_number(info, info->list[i]);
		i++;
	}
	free_array(info->list);
	info->list = NULL;
	return (0);
}

static int	check_array(t_info *info)
{
	free_array(info->list);
	info->list = NULL;
	if (is_digit(info->str))
		ft_error(info, NULL);
	if (check_int(info->str, info))
		ft_error(info, NULL);
	get_number(info, info->str);
	return (0);
}

int	check_argv(int argc, char **argv, t_info *info)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		info->str = ft_strdup(argv[i++]);
		if (!info->str)
			ft_error(info, NULL);
		info->list = ft_split(info->str, ' ');
		if (!info->list[1])
			check_array(info);
		else
			check_list(info);
		free(info->str);
		info->str = NULL;
	}
	return (0);
}
