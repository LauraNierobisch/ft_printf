/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:44:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/11 16:50:21 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extra_temp(unsigned long n, int base, int *count)
{
	int	temp;

	temp = print_digit(n, base);
	if (temp == -1)
		return (-1);
	else
	{
		*count += temp;
		return (0);
	}
}

int	print_digit(int n, int base)

{
	const char letters[] = "0123456789";
	int count;
	char print;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		count++;
	}
	print = letters[n % base];
	n = n / base;
	if (n > 0)
	{
		if (extra_temp(n, base, &count) == -1)
			return (-1);
	}
	if (write(1, &print, 1) == -1)
		return (-1);
	return (count + 1);
}
