/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:38:57 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/28 22:32:59 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list va, char n, int *i)
{
	int	len;

	len = 0;
	if (n == 'c')
		len += ft_putchar(va_arg(va, int));
	else if (n == 's')
		len += ft_putstr(va_arg(va, char *));
	else if (n == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putptr(va_arg(va, unsigned long));
	}
	else if (n == 'd' || n == 'i')
		len += ft_putnbr(va_arg(va, int));
	else if (n == 'u')
		len += ft_putnbuns(va_arg(va, unsigned int));
	else if (n == 'x' || n == 'X')
		len += ft_putnbhex(va_arg(va, unsigned int), n);
	else if (n == '%')
		len += write(1, "%", 1);
	else
	(*i)--;
	return (len);
}

int	ft_printf(const char *n, ...)
{
	va_list	va;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = write(1, "", 0);
	if (len < 0)
		return (-1);
	va_start(va, n);
	while (n[i])
	{
		if (n[i] == '%')
		{
			while (n[i + 1] == ' ')
			i++;
			j += ft_format(va, n[++i], &i);
		}
		else
		j += ft_putchar(n[i]);
		i++;
	}
	va_end(va);
	return (j);
}
