/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:43:22 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/11 16:50:06 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digit(va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += hex_low(va_arg(ap, unsigned int), 16);
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (specifier == 'i')
		count += print_int(va_arg(ap, int));
	else if (specifier == 'u')
		count += unsigned_decimal(va_arg(ap, unsigned int), 10);
	else if (specifier == 'X')
		count += hex_up(va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			temp = print_format(*(++format), ap);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			temp = write(1, format, 1);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		++format;
		if (count == -1)
			return (-1);
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned long	ui;

// 	int a, b;
// 	ui = 18446744073709551615;
// 	a = printf("real: %p\n", (void *)ui);
// 	b = ft_printf("copy: %p\n", (void *)ui);
// 	printf("\n\nStandard: %i :: Mine: %i\n\n", a, b);
// 	return (0);
// }

// 0123456789
// 0123456789abcdef =Hexadecimal lowercase
// 0123456789ABCDEF =Hexadecimal uppercase
