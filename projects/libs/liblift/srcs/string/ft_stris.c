/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:53:38 by lroux             #+#    #+#             */
/*   Updated: 2019/02/24 22:32:10 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"

int	ft_stris(char *s, int (*is)(int c))
{
	s--;
	while (*(++s))
		if (!is(*s))
			return (0);
	return (1);
}
