/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:54:09 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/03 09:02:55 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		uc;
	size_t				x;

	a = (const unsigned char *)s;
	uc = (unsigned char)c;
	x = 0;
	while (x < n)
	{
		if (a[x] == uc)
			return ((void *)(a + x));
		x++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char    c[] = "thaera";
	printf("%p\n",ft_memchr(c,'e',3));
	printf("%p\n",memchr(c,'e',3));
	printf("%p",(c));

}*/