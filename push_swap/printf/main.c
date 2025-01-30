/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:07:47 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/11 00:40:46 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, world!");
	ft_printf("Pointer: %p\n", &main);
	ft_printf("Decimal: %d\n", 42);
	ft_printf("Unsigned: %u\n", 3000000000U);
	ft_printf("Hexadecimal: %x\n", 255);
	ft_printf("Percentage: %%\n");
	printf("Unsupported: %q\n");
	return (0);
}
