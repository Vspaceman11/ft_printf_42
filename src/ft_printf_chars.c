/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:07:09 by vpushkar          #+#    #+#             */
/*   Updated: 2025/03/28 13:41:00 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/**
 * @brief Writes a single character to the given file descriptor.
 *
 * This function writes the character `c` to the file descriptor `fd`.
 * If an error occurs, it returns -1, otherwise 1.
 *
 * @param c The character to write.
 * @param fd The file descriptor where the character is written.
 * @return 1 on success, -1 on failure.
 */
int	ft_printf_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

/**
 * @brief Writes a string to the given file descriptor.
 *
 * This function writes the string `s` to the file descriptor `fd`, one character
 * at a time. If the string is NULL, it is treated as "(null)".
 * The function returns the number of characters written or -1 on failure.
 *
 * @param s The string to write.
 * @param fd The file descriptor where the string is written.
 * @return The number of characters written, or -1 on failure.
 */
int	ft_printf_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_printf_putchar_fd(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (i);
}
