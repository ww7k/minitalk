/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:03:44 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/28 22:36:57 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putptr(unsigned long pt);
int	ft_putnbuns(unsigned int n);
int	ft_putnbr(int n);
int	ft_putnbhex(unsigned int n, char l);
int	ft_putchar(int c);
int	ft_printf(const char *n, ...);

#endif
