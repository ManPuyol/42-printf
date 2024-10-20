/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:03:51 by manorteg          #+#    #+#             */
/*   Updated: 2024/10/19 20:03:51 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <aio.h>
#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(char const *, ...);

int ft_vprintf(char const *, va_list);

#endif

