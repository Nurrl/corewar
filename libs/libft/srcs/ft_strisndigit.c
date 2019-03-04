/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisndigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:59:31 by lroux             #+#    #+#             */
/*   Updated: 2018/11/30 18:37:16 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisndigit(char *s, size_t n)
{
	--s;
	while (*(++s) && n--)
		if (!ft_isdigit(*s))
			return (0);
	return (1);
}