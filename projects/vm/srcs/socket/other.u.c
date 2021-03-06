/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _other.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:54:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 11:54:17 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

static const unsigned char g_base_table[65] = \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static unsigned char		*init_out_base(
		void *src, size_t len, size_t *out_len)
{
	unsigned char	*out;
	size_t			olen;

	olen = 4 * (len / 3 + 1) + 1;
	if (olen < len || out_len == NULL || src == NULL)
		return (NULL);
	out = (unsigned char *)malloc(olen * sizeof(unsigned char));
	if (out == NULL)
		return (NULL);
	return (out);
}

static inline unsigned char	*set_pos_value(
	unsigned char *pos, const unsigned char *in)
{
	*pos++ = g_base_table[in[0] >> 2];
	*pos++ = g_base_table[((in[0] & 0x3) << 4) | (in[1] >> 4)];
	*pos++ = g_base_table[((in[1] & 0xf) << 2) | (in[2] >> 6)];
	*pos++ = g_base_table[in[2] & 0x3f];
	return (pos);
}

static inline unsigned char	*finish_encoding(
	unsigned char *pos, const unsigned char *in, const unsigned char *end)
{
	size_t	diff;

	diff = end - in;
	if (diff)
	{
		*pos++ = g_base_table[in[0] >> 2];
		if (diff == 1)
		{
			*pos++ = g_base_table[(in[0] & 0x3) << 4];
			*pos++ = '=';
		}
		else
		{
			*pos++ = g_base_table[((in[0] & 0x3) << 4) | (in[1] >> 4)];
			*pos++ = g_base_table[(in[1] & 0xf) << 2];
		}
		*pos++ = '=';
	}
	*pos = 0;
	return (pos);
}

unsigned char				*encode_base64(
		void *src, size_t len, size_t *out_len)
{
	unsigned char		*out;
	unsigned char		*pos;
	const unsigned char	*end;
	const unsigned char	*in;

	if (!(out = init_out_base(src, len, out_len)))
		return (NULL);
	end = src + len;
	pos = out;
	in = src;
	while (end - in >= 3)
	{
		pos = set_pos_value(pos, in);
		in += 3;
	}
	pos = finish_encoding(pos, in, end);
	*out_len = pos - out;
	return (out);
}

void						clean_simple_ptr(void *p)
{
	char **t;

	t = p;
	if (t && *t)
		free(*t);
}
