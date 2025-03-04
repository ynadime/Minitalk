/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:43:45 by ynadime           #+#    #+#             */
/*   Updated: 2025/03/03 12:27:50 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_client(int *bit, char *character, int *client_pid, int new_pid)
{
	*bit = 0;
	*character = 0;
	*client_pid = new_pid;
}

void	handle_signal(int sig, siginfo_t *info, void *more_info)
{
	static int	bit;
	static char	character;
	static int	client_pid;

	if (client_pid != info->si_pid)
		reset_client(&bit, &character, &client_pid, info->si_pid);
	if (sig == SIGUSR1)
		character |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR1);
		}
		else
			ft_printf("%c", character);
		character = 0;
		bit = 0;
	}
	(void)more_info;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: ./server\n");
		exit(1);
	}
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}
