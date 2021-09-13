/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:40:25 by nide-mel          #+#    #+#             */
/*   Updated: 2021/07/23 11:44:16 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_let(char c);
int			ft_putstr(char *str);
char		*ft_itoa(int n);
int			ft_conv_int(int number);
int			ft_len(long int nbr);
char		*ft_strdup(char *src);
int			ft_strlen(char *str);
int			ft_base(unsigned long long n, char *base);
long int	ft_abs(long int nbr);
int			ft_con_pointer(unsigned long long n);
char		*ft_itoa_base(unsigned long long n, char *base);
int			ft_conv_unint(unsigned int number);

#endif
