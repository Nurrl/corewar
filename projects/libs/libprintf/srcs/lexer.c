/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:15:05 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 18:08:47 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void	pflexparam(t_flag *flag, char **format)
{
	char *dum;

	flag->param = -1;
	if ((dum = ft_strchr(*format, '$'))
			&& ft_strisn(*format, dum - *format, &ft_isdigit))
		flag->param = ft_atoi(*format);
	if (flag->param != -1)
		*format = dum + 1;
}

void	pflexflags(t_flag *flag, char **format)
{
	flag->flags = 0;
	while (**format == '#' || **format == '-' || **format == '+'
			|| **format == ' ' || **format == '0')
	{
		flag->flags |= (**format == '#' && !(flag->flags & FLAGALTER))
			? FLAGALTER : 0;
		flag->flags |= (**format == '-' && !(flag->flags & FLAGMINUS))
			? FLAGMINUS : 0;
		flag->flags |= (**format == '+' && !(flag->flags & FLAGPLUS))
			? FLAGPLUS : 0;
		flag->flags |= (**format == ' ' && !(flag->flags & FLAGBLANK))
			? FLAGBLANK : 0;
		flag->flags |= (**format == '0' && !(flag->flags & FLAGZERO))
			? FLAGZERO : 0;
		++(*format);
	}
	if ((flag->flags & FLAGPLUS) && (flag->flags & FLAGBLANK))
		flag->flags ^= FLAGBLANK;
	if ((flag->flags & FLAGMINUS) && (flag->flags & FLAGZERO))
		flag->flags ^= FLAGZERO;
}

void	pflexwidth(t_flag *flag, char **format, va_list ap)
{
	char *dum;

	if ((dum = ft_strchr(*format, '*'))
			&& ft_strisn(*format, dum - *format, &ft_isdigit))
	{
		*format = dum;
		flag->width = va_arg(ap, int);
		if (flag->width < 0)
		{
			flag->flags |= (!(flag->flags & FLAGMINUS) ? FLAGMINUS : 0);
			flag->width = -flag->width;
		}
		++(*format);
		if (!ft_isdigit(**format))
			return ;
	}
	dum = *format;
	while (ft_isdigit(**format))
		++(*format);
	flag->width = (*format == dum) ? -1 : ft_atoi(dum);
}

void	pflexprecision(t_flag *flag, char **format, va_list ap)
{
	char *dum;

	flag->precision = -1;
	if (**format == '.')
		++(*format);
	else
		return ;
	if (**format == '*')
	{
		flag->precision = va_arg(ap, int);
		if (flag->precision < 0)
			flag->precision = -1;
		++(*format);
		return ;
	}
	dum = *format;
	while (ft_isdigit(**format))
		++(*format);
	if (*format != dum)
		flag->precision = ft_atoi(dum);
	else
		flag->precision = 0;
}

t_bool	pflexlandt(t_flag *flag, char **format)
{
	char *dum;

	dum = *format;
	while ((**format == 'l' || **format == 'h' || **format == 'L'
			|| **format == 'j' || **format == 'z' || **format == 't')
			&& !pfisvalid(**format))
	{
		if (!**format)
			return (false);
		++(*format);
	}
	if (!**format || !pfisvalid(**format))
		return (false);
	flag->type = **format;
	pfflaglen(flag, dum, format);
	return (true);
}
