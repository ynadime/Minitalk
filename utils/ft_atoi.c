/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:48:30 by ynadime           #+#    #+#             */
/*   Updated: 2025/03/02 15:48:31 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_atoi_error(void)
{
	ft_printf("Invalid PID!");
	exit(1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	results;

	i = 0;
	sign = 1;
	results = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		results = (results * 10) + (str[i] - '0');
		if ((results * sign) > INT_MAX || (results * sign) < INT_MIN)
			ft_atoi_error();
		i++;
	}
	if (str[i])
		ft_atoi_error();
	return (results * sign);
}
