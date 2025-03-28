/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:12:30 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/28 13:41:30 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Writes an integer to fd.
 *
 * This function recursively converts the integer `n` into its string
 * representation and writes it to the file descriptor `fd`. It handles the
 * special case of the minimum integer value (-2147483648).
 *
 * @param n The integer to convert.
 * @param fd The file descriptor to write to.
 * @return The number of characters written, or -1 if error occurs.
 */
int	ft_printf_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_printf_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		if (ft_printf_putchar_fd('-', fd) == -1)
			return (-1);
		n = -n;
		count ++;
	}
	if (n >= 10)
	{
		count += ft_printf_putnbr_fd(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	if (ft_printf_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	count++;
	return (count);
}

/**
 * @brief Writes an unsigned integer to fd.
 *
 * This function recursively converts the unsigned integer `n` into its
 * string representation and writes it to the file descriptor `fd`.
 *
 * @param n The unsigned integer to convert.
 * @param fd The file descriptor to write to.
 * @return The number of characters written, or -1 if error occurs.
 */
int	ft_printf_put_unsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_printf_put_unsigned_fd(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	if (ft_printf_putchar_fd(n % 10 + '0', fd) == -1)
		return (-1);
	count++;
	return (count);
}
