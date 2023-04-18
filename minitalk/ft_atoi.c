/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:48:12 by wwatik            #+#    #+#             */
/*   Updated: 2023/03/24 23:48:15 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long long	res;
	long long	n;
	int			sig;

	sig = 1;
	res = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = res;
		res = res * 10 + *str - 48;
		if (n != res / 10 && sig == -1)
			return (0);
		else if (n != res / 10 && sig == 1)
			return (-1);
		str++;
	}
	return (res * sig);
}
