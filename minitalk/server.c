/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:37:52 by wwatik            #+#    #+#             */
/*   Updated: 2023/03/23 16:37:56 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_getsig(int sig, siginfo_t *info, void *ptr)
{
	static char		s = 0;
	static int		i = 0;
	static pid_t	pid = 0;

	(void)ptr;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		s = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		s |= 1 << (7 - i);
	else
		s |= 0 << (7 - i);
	i++;
	if (i == 8)
	{
		write(1, &s, 1);
		s = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_getsig;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
