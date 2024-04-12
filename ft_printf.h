/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:48:47 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/11 13:41:35 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		unsigned_decimal(unsigned int n, int base);
int		ft_printf(const char *format, ...);
int		hex_low(unsigned long n, int base);
int		hex_up(long long n, int base);
int		print_char(int c);
int		print_digit(int n, int base);
int		print_int(long long n);
int		print_pointer(void *ptr);
int		print_str(char *s);
void	ft_putchar_fd(char c);
#endif
