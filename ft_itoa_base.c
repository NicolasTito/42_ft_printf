/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:59:10 by nide-mel          #+#    #+#             */
/*   Updated: 2021/08/10 15:10:59 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_len_base(unsigned long long n, int base)
{
	unsigned long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char				*str;
	unsigned long		len;
	unsigned long long	lbase;

	if (n == 0)
		return (ft_strdup("0"));
	lbase = ft_strlen(base);
	len = ft_len_base(n, lbase);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!lbase)
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = base[n % lbase];
		n = n / lbase;
		len--;
	}
	return (str);
}

int	ft_base(unsigned long long n, char *base)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa_base(n, base);
	counter += ft_putstr(str);
	free (str);
	return (counter);
}

int	ft_con_pointer(unsigned long long n)
{
	char	*str;
	int		counter;

	counter = 0;
	if (n == 0)
		counter += ft_putstr("0x0");
	else if (n != 0)
	{
		counter += ft_putstr("0x");
		str = ft_itoa_base(n, "0123456789abcdef");
		counter += ft_putstr(str);
		free (str);
	}
	return (counter);
}

int	ft_conv_unint(unsigned int number)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa_base(number, "0123456789");
	counter += ft_putstr(str);
	free (str);
	return (counter);
}
