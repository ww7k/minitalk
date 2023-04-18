/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:01:28 by wwatik            #+#    #+#             */
/*   Updated: 2023/03/27 20:01:33 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	msg(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Your message was received", 25);
		exit(0);
	}
}

void	ft_sigbit(char n, int pid)
{
	char	s;
	int		i;

	i = 7;
	while (i >= 0)
	{
		s = n >> (i);
		if (s & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(900);
		i--;
	}
}

void	ft_error_check(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (!((argv[j] >= 48) && (argv[j] <= 57)))
		{
			write(1, "Invalid PID\n", 12);
			exit(1);
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;

	i = -1;
	if (argc != 3)
		return (write(1, "3 arguments needed\n", 19), 1);
	else
	{
		ft_error_check(argv[1]);
		pid = ft_atoi(argv[1]);
		if (pid == 0)
			return (write(1, "Invalid PID\n", 12), 1);
		if (kill(pid, 0) == -1)
			return (write(1, "error\n", 6), 1);
		while (argv[2][++i])
			ft_sigbit(argv[2][i], pid);
		signal(SIGUSR2, msg);
		ft_sigbit(argv[2][i], pid);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
