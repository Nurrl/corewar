/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:05:49 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 22:28:19 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/types.h"
#include "lift/memory.h"
#include <stdlib.h>

static size_t	memset1b(void **dst, unsigned char c)
{
	*((t_u8*)*dst) = c;
	*dst += 1;
	return (1);
}

static size_t	memset2b(void **dst, unsigned char c)
{
	t_u16 res;

	res = c;
	res = (res << 8) ^ c;
	*((t_u16*)*dst) = res;
	*dst += 2;
	return (2);
}

static size_t	memset4b(void **dst, unsigned char c)
{
	t_u32 res;

	res = c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	*((t_u32*)*dst) = res;
	*dst += 4;
	return (4);
}

static size_t	memset8b(void **dst, unsigned char c)
{
	t_u64 res;

	res = c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	res = (res << 8) ^ c;
	*((t_u64*)*dst) = res;
	*dst += 8;
	return (8);
}

void			*ft_memset(void *b, int c, size_t len)
{
	char *init;

	init = b;
	while (len)
	{
		if (len < 2)
			len -= memset1b(&b, c);
		else if (len < 4)
			len -= memset2b(&b, c);
		else if (len < 8)
			len -= memset4b(&b, c);
		else
			len -= memset8b(&b, c);
	}
	return (init);
}
