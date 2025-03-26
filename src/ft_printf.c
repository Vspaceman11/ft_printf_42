/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:09 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/26 17:33:19 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_uns_putnbr_fd(unsigned int n, int fd);
static int	ft_putptr_fd(uintptr_t ptr, int fd);
static int	ft_puthex_low_fd(unsigned int n, int fd);
static int	ft_puthex_upp_fd(unsigned int n, int fd);
static int	ft_putchar_cust_fd(char c, int fd);
static int	ft_putstr_cust_fd(char *s, int fd);
static int	ft_putnbr_cust_fd(int n, int fd);

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
				count += ft_putnbr_cust_fd(digit, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == 'c')
			{
				if (ft_putchar_cust_fd((char)va_arg(args, int), 1) == -1)
					return (-1);
				i += 2;
				count++;
				continue ;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				count += ft_putstr_cust_fd(str, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == 'u')
			{
				digit = va_arg(args, unsigned int);
				count += ft_uns_putnbr_fd(digit, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == 'p')
			{
				ptr = va_arg(args, void *);
				count += ft_putptr_fd((uintptr_t)ptr, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == 'x')
			{
				digit = va_arg(args, unsigned int);
				count += ft_puthex_low_fd(digit, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == 'X')
			{
				digit = va_arg(args, unsigned int);
				count += ft_puthex_upp_fd(digit, 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
			else if (format[i + 1] == '%')
			{
				count += ft_putchar_cust_fd('%', 1);
				if (count == -1)
					return (-1);
				i += 2;
				continue ;
			}
		}
		if (ft_putchar_cust_fd(format[i], 1) == -1)
			return (-1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}

static int	ft_uns_putnbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_uns_putnbr_fd(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar_cust_fd(n % 10 + '0', fd) == -1)
		return (-1);
	count++;
	return (count);
}

static int	ft_putptr_fd(uintptr_t ptr, int fd)
{
	char	*hex_digits;
	char	hex[16];
	int		i;
	int		count;

	hex_digits = "0123456789abcdef";
	i = 0;
	count = 2;
	if (ft_putstr_cust_fd("0x", fd) == -1)
		return (-1);
	if (ptr == 0)
	{
		ft_putchar_cust_fd('0', fd);
		return (3);
	}
	while (ptr != 0)
	{
		hex[i++] = hex_digits[ptr % 16];
		ptr = ptr / 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_cust_fd(hex[i], fd);
	return (count + 2);
}

static int	ft_puthex_low_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_low_fd(n / 16, fd);
	if (count == -1)
		return (-1);
	if (write(fd, &hex_digits[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int	ft_puthex_upp_fd(unsigned int n, int fd)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_upp_fd(n / 16, fd);
	if (count == -1)
		return (-1);
	if (write(fd, &hex_digits[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int	ft_putchar_cust_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_putstr_cust_fd(char *s, int fd)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_putchar_cust_fd(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_cust_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_cust_fd("-2147483648", fd));
	if (n < 0)
	{
		if (ft_putchar_cust_fd('-', fd) == -1)
			return (-1);
		n = -n;
		count ++;
	}
	if (n >= 10)
	{
		count += ft_putnbr_cust_fd(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar_cust_fd(n % 10 + '0', fd) == -1)
		return (-1);
	count++;
	return (count);
}
