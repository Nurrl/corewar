/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswp32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:27:03 by lroux             #+#    #+#             */
/*   Updated: 2019/04/05 18:27:16 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/types.h"
#include "lift/memory.h"

t_u32	ft_bswp32(t_u32 val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}
