/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:22:48 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/27 14:23:02 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf_put_pointer_fd(uintptr_t ptr, int fd)
{
	char	*hex_digits;
	char	hex[16];
	int		i;
	int		count;

	hex_digits = "0123456789abcdef";
	i = 0;
	count = 2;
	if (ft_printf_putstr_fd("0x", fd) == -1)
		return (-1);
	if (ptr == 0)
	{
		ft_printf_putchar_fd('0', fd);
		return (3);
	}
	while (ptr != 0)
	{
		hex[i++] = hex_digits[ptr % 16];
		ptr = ptr / 16;
	}
	count = i;
	while (--i >= 0)
		ft_printf_putchar_fd(hex[i], fd);
	return (count + 2);
}
