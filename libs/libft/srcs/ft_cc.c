/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:53:50 by lroux             #+#    #+#             */
/*   Updated: 2018/11/22 10:35:30 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_cc(const char *s, char c)
{
	int count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}