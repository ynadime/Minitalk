/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:44:09 by ynadime           #+#    #+#             */
/*   Updated: 2025/03/03 12:29:16 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char character)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (character & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Failed while sending the message!\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Failed while sending the message!\n");
				exit(1);
			}
		}
		bit--;
		usleep(300);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		send_char(pid, message[i++]);
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	char	*message;
	int		pid;

	if (ac != 3)
	{
		ft_printf("Error\nInvalid number of arguments!\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("Invalid PID!\n");
		exit(1);
	}
	send_message(pid, message);
}
