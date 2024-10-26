/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:07:02 by manorteg          #+#    #+#             */
/*   Updated: 2024/10/26 12:07:02 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_char(va_list args)
{
	char	str;

	str = va_arg(args, int);
	ft_putchar_fd(str, 1);
	return (1);
}

int	print_nbr(va_list args, char *base)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_base(nbr, base);
	return (count_digits(nbr));
}

int	print_unsisgned_nbr(va_list args, char *base)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_base(nbr, base);
	return (count_digits(nbr));
}

int	print_pointer(va_list args)
{
	unsigned long	pointer;

	pointer = va_arg(args, unsigned long);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(pointer, "0123456789abcdef");
	return (count_digits(pointer) + 2);
}