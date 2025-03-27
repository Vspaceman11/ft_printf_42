/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:09 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/27 16:09:25 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_printf_handle_format(char specifier, va_list args);
static void	ft_var_declaration(int *i, int *count);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	ft_var_declaration(&i, &count);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_printf_handle_format(format[i], args);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (ft_printf_putchar_fd(format[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

static int	ft_printf_handle_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'i' || specifier == 'd')
		count = ft_printf_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		count = ft_printf_put_unsigned_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 'c')
		count = ft_printf_putchar_fd((char)va_arg(args, int), 1);
	else if (specifier == 's')
		count = ft_printf_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == '%')
		count = ft_printf_putchar_fd('%', 1);
	else if (specifier == 'p')
		count = ft_printf_put_pointer_fd((uintptr_t)va_arg(args, void *), 1);
	else if (specifier == 'x')
		count = ft_printf_puthex_lower_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 'X')
		count = ft_printf_puthex_upper_fd(va_arg(args, unsigned int), 1);
	else
		return (-1);
	return (count);
}

static void	ft_var_declaration(int *i, int *count)
{
	*i = 0;
	*count = 0;
}
