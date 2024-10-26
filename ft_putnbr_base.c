/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:04:11 by manorteg          #+#    #+#             */
/*   Updated: 2024/10/26 12:04:11 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	invalid_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (base[i])
	{
		j = 0;
		count = 0;
		while (base[j])
		{
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || count > 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base_recursive(int num, char *base, int lenght, int *printed_chars)
{
	if (num >= lenght)
		ft_putnbr_base_recursive(num / lenght, base, lenght);
	write(1, &(char){base[num % lenght]}, 1);
	*printed_chars++;
}

int	ft_putnbr_base(long num, char *base)
{
	int		base_lenght;
	int		printed_chars;

	base_lenght = ft_strlen(base);
	print_chars = 0;
	if (base_lenght <= 1 || invalid_base(base) == 1)
		return (0);
	if (num < 0)
	{
		write(1, "-", 1);
		printed_chars++;
		num *= -1;
	}
	if (num >= base_lenght)
		ft_putnbr_base_recursive(num / base_lenght, base, base_lenght, &printed_chars);
	write(1, &(char){base[num % base_lenght]}, 1);
	printed_chars++;
	return (printed_chars);
}
