/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:17:23 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/28 22:32:14 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbhex(unsigned int n, char l)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbhex((n / 16), l);
		len += ft_putnbhex((n % 16), l);
	}
	else if (n <= 9)
		len += ft_putchar(n + '0');
	else
	{
		if (l == 'x')
			len += ft_putchar(n + 87);
		else if (l == 'X')
			len += ft_putchar(n + 55);
	}
	return (len);
}
