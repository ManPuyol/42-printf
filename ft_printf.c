/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:05:32 by manorteg          #+#    #+#             */
/*   Updated: 2024/10/19 20:05:32 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(va_list args)
{
    char *str;

    str = va_arg(args, char *);
    ft_putstr_fd(str,1);
    return (ft_strlen(str));
}

int print_char(va_list args)
{
    char str;

    str = va_arg(args, int);
    ft_putchar_fd(str,1);
    return (1);
}

static int	count_digits(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_base_recursive(int num, char *base, int lenght)
{
	if (num >= lenght)
		ft_putnbr_base_recursive(num / lenght, base, lenght);
	write(1, &(char){base[num % lenght]}, 1);
}

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

void	ft_putnbr_base(long num, char *base)
{
	int		base_lenght;

	base_lenght = ft_strlen(base);
	if (base_lenght <= 1 || invalid_base(base) == 1)
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= base_lenght)
		ft_putnbr_base_recursive(num / base_lenght, base, base_lenght);
	write(1, &(char){base[num % base_lenght]}, 1);
}

int print_nbr(va_list args, char *base)
{
    int nbr;

    nbr = va_arg(args, int);
    ft_putnbr_base(nbr, base);
    return (count_digits(nbr));
}

int print_unsisgned_nbr(va_list args, char *base)
{
    unsigned int nbr;

    nbr = va_arg(args, unsigned int);
    ft_putnbr_base(nbr, base);
    return (count_digits(nbr));
}

int print_pointer(va_list args)
{
    unsigned long pointer;

    pointer = va_arg(args, unsigned long);
    ft_putstr_fd("0x",1);
    ft_putnbr_base(pointer, "0123456789abcdef");
    return (count_digits(pointer) + 2);
}

int print_format(char sentence, va_list args)
{
    int printed_chars;

    printed_chars = 0;
    switch (sentence)
    {
    case 'c':
        return (print_char(args));      
    case 's':
        return (print_string(args));
    case 'p':
        return (print_pointer(args));
    case 'd':
        return (print_nbr(args, "0123456789"));
    case 'i':
        return (print_nbr(args, "0123456789"));
    case 'u':
        return (print_unsisgned_nbr(args, "0123456789"));
    case 'x':
        return (print_nbr(args, "0123456789abcdef"));
    case 'X':
        return (print_nbr(args, "0123456789ABCDEF"));
    case '%':
        ft_putchar_fd('%',1);
        return (1);  
    default:
        break;
    }

    return (printed_chars);
}

int ft_vprintf(char const *sentence, va_list args)
{
    int printed_chars;

    printed_chars = 0;
    while (*sentence)
    {
        if (*sentence == '%')
        {
            sentence++;
            printed_chars += print_format(*sentence, args);
        }
        else
        {
            ft_putchar_fd(*sentence,1);
            printed_chars++;
        }
        sentence++;
    }
    return (printed_chars);
}

// int print_pointer(va_list args)
// {
//     unsigned long pointer;
//     int printed_chars;

//     pointer = va_arg(args, unsigned long);
//     printed_chars = 0;
//     ft_putstr("0x");
//     printed_chars += 2;
//     printed_chars += print_hexa(pointer);
//     return (printed_chars);
// }

int ft_printf(char const *sentence, ...)
{
    va_list args;
    int printed_chars;

    va_start(args, sentence);
    printed_chars = ft_vprintf(sentence, args);
    va_end(args);
    return (printed_chars);
}

// int main()
// {
//     char c = 'A';
//     char *s = "Hello, World!";
//     void *p = (void *)0x12345678;
//     int d = -42.24;
//     int i = 033;
//     unsigned int u = 3000000000;
//     int x = 0xabcdef;
//     int X = 0xABCDEF;

//     // Testing each format specifier
//     printf("Standard printf:\n");
//     printf("%%c: %c\n", c);
//     printf("%%s: %s\n", s);
//     printf("%%p: %p\n", p);
//     printf("%%d: %d\n", d);
//     printf("%%i: %i\n", i);
//     printf("%%u: %u\n", u);
//     printf("%%x: %x\n", x);
//     printf("%%X: %X\n", X);
//     printf("%%%%: %%\n");

//     printf("\nYour ft_printf:\n");
//     ft_printf("%%c: %c\n", c);
//     ft_printf("%%s: %s\n", s);
//     ft_printf("%%p: %p\n", p);
//     ft_printf("%%d: %d\n", d);
//     ft_printf("%%i: %i\n", i);
//     ft_printf("%%u: %u\n", u);
//     ft_printf("%%x: %x\n", x);
//     ft_printf("%%X: %X\n", X);
//     ft_printf("%%%%: %%\n");

//     // // Testing edge cases
//     // printf("\nTesting edge cases:\n");
//     // printf("Standard printf:\n");
//     // printf("NULL string: %s\n", NULL);
//     // printf("INT_MAX: %d\n", INT_MAX);
//     // printf("INT_MIN: %d\n", INT_MIN);
//     // printf("UINT_MAX: %u\n", UINT_MAX);

//     // printf("\nYour ft_printf:\n");
//     // ft_printf("NULL string: %s\n", NULL);
//     // ft_printf("INT_MAX: %d\n", INT_MAX);
//     // ft_printf("INT_MIN: %d\n", INT_MIN);
//     // ft_printf("UINT_MAX: %u\n", UINT_MAX);

//     return (0);
// }