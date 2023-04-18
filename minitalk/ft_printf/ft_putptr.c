/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:57:07 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/25 21:57:09 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr((n / 16));
		len += ft_putptr((n % 16));
	}
	else if (n <= 9)
		len += ft_putchar(n + '0');
	else
		len += ft_putchar(n + 87);
	return (len);
}
