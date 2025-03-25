/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:09 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/25 17:03:38 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	len_count(long n);
static void	ft_uns_putnbr_fd(unsigned int n, int fd);
static int	ft_putptr_fd(uintptr_t ptr, int fd);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	long	digit;
	char	*str;
	void	*ptr;

	i = 0;
	count = 0;
	digit = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				digit = va_arg(args, int);
				ft_putnbr_fd(digit, 1);
				count += len_count(digit);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'c')
			{
				ft_putchar_fd((char)va_arg(args, int), 1);
				i += 2;
				count++;
				continue;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				if (str)
				{
					ft_putstr_fd(str, 1);
					count += ft_strlen(str);
				}
				else
				{
					ft_putstr_fd("(null)", 1);
					count += 6;
				}
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'u')
			{
				digit = va_arg(args, unsigned int);
				ft_uns_putnbr_fd(digit, 1);
				count += len_count(digit);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'p')
			{
				ptr = va_arg(args, void *);
				count += ft_putptr_fd((uintptr_t)ptr, 1);
				i +=2;
				continue;
			}
			// else if (format[i + 1] == 'x')
			// {

			// }
			// else if (format[i + 1] == 'X')
			// {

			// }
			else if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
				i += 2;
				continue;
			}
		}
		ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}

static int	len_count(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
static void	ft_uns_putnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_uns_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
}
static int	ft_putptr_fd(uintptr_t ptr, int fd)
{
	char	*hex_digits;
	char	hex[16];
	int		i;
	int	count;

	hex_digits = "0123456789abcdef";
	i = 0;
	count = 2;
	ft_putstr_fd("0x", fd);
	if (ptr == 0)
	{
		ft_putchar_fd('0', fd);
		return (count + 1);
	}
	while (ptr != 0)
	{
		hex[i++] = hex_digits[ptr % 16];
		ptr = ptr / 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_fd(hex[i], fd);
	return (count + 2);
}
