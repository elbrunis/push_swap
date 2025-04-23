/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biniesta <biniesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:47:37 by biniesta          #+#    #+#             */
/*   Updated: 2025/04/23 13:20:12 by biniesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sing;

	num = 0;
	sing = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
	{
		nptr++;
	}
	if ('-' == *nptr || '+' == *nptr)
	{
		if (*nptr == '-')
		{
			sing = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sing);
}

long int	ft_atol(const char *nptr)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+') 
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (num == LONG_MAX / 10 && (*nptr - '0') > (LONG_MAX % 10))
		{
		if (sign == 1)
			return LONG_MAX;
		else
			return LONG_MIN;
		}
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return num * sign;
}