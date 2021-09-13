/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:08:17 by nide-mel          #+#    #+#             */
/*   Updated: 2021/07/23 11:54:59 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_letter(char c, va_list arg)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(arg, char *));
	else if (c == '%')
		counter += ft_putchar('%');
	else if (c == 'd')
		counter += ft_conv_int(va_arg(arg, int));
	else if (c == 'i')
		counter += ft_conv_int(va_arg(arg, int));
	else if (c == 'u')
		counter += ft_conv_unint(va_arg(arg, unsigned int));
	else if (c == 'p')
		counter += ft_con_pointer(va_arg(arg, unsigned long));
	else if (c == 'x')
		counter += ft_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	return (counter);
}

static int	ft_start(const char *format, va_list args)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (format[i] != '\0')
	{
		if (!format[i])
			return (counter);
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (!ft_let(format[i]))
				return (counter);
			else
				counter += ft_letter(format[i], args);
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	counter = ft_start(format, args);
	va_end(args);
	return (counter);
}
