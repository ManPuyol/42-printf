/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:07:02 by manorteg          #+#    #+#             */
/*   Updated: 2024/10/26 18:28:07 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
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
	if (pointer == 0)
	{
		ft_putstr_fd("(nil)",1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(pointer, "0123456789abcdef");
	return (count_digits(pointer) + 2);
}
