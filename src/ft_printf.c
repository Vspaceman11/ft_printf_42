/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:17:09 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/27 16:23:40 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_printf_handle_format(char specifier, va_list args);
static void	ft_var_declaration(int *i, int *count);
/**
 * @brief Custom implementation of printf.
 *
 * This function is a simplified version of the standard printf function.
 * It handles the `%` format specifier for different data types and writes
 * the formatted output to the standard output (fd = 1).
 * It supports integers, unsigned integers, characters, strings, pointers,
 * and hexadecimal formatting.
 *
 * @param format The format string, potentially containing format specifiers
 * 			like `%d`, `%s`, etc.
 * @return The number of characters printed (excluding the null byte),
 * 			or -1 in case of an error.
 */
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
/**
 * @brief Handles format specifiers and calls the corresponding functions.
 *
 * This function processes a single format specifier and calls the appropriate
 * function to handle the corresponding type of argument (e.g., integer, string,
 * pointer, etc.).
 *
 * @param specifier The format specifier character (e.g., 'd', 's', '%').
 * @param args The variable argument list containing the value to format.
 * @return The number of characters printed, or -1 in case of an error.
 */

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
/**
 * @brief Initializes variables i and count.
 *
 * This function initializes the index variable `i` and the counter `count`
 * to zero, preparing them for use in the main printf function.
 *
 * @param i Pointer to the index variable.
 * @param count Pointer to the counter variable.
 */

static void	ft_var_declaration(int *i, int *count)
{
	*i = 0;
	*count = 0;
}
