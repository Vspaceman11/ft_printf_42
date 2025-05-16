/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:21:43 by vpushkar          #+#    #+#             */
/*   Updated: 2025/05/16 15:43:18 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);

int	ft_printf_putchar_fd(char c, int fd);
int	ft_printf_putstr_fd(char *s, int fd);
int	ft_printf_putnbr_fd(int n, int fd);
int	ft_printf_put_unsigned_fd(unsigned int n, int fd);
int	ft_printf_puthex_lower_fd(unsigned int n, int fd);
int	ft_printf_puthex_upper_fd(unsigned int n, int fd);
int	ft_printf_put_pointer_fd(uintptr_t ptr, int fd);

#endif
