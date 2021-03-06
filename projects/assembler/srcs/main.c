/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:57:27 by lroux             #+#    #+#             */
/*   Updated: 2019/05/14 13:37:27 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lift/memory.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"
#include <string.h>

int	cleanup(int r, t_asm *env)
{
	t_tok	*tok;

	(void)env;
	free(env->oname);
	free(env->sstring);
	free((void*)env->scstring);
	if (__APPLE__)
		free(strerror(0));
	while ((tok = ll_pop(&env->syms, 0)))
		free(tok);
	while ((tok = ll_pop(&env->refs, 0)))
		free(tok);
	while ((tok = ll_pop(&env->tokens, 0)))
	{
		free(tok->val);
		free(tok);
	}
	return (r);
}

int	main(int ac, char **av)
{
	static t_asm	env;

	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!(env.tokens = lexer(&env, av[1]))
			|| !(env.oname = ft_calloc(ft_strlen(av[1]) + 3, sizeof(char)))
			|| env.isbinary)
		return (cleanup(failure, &env));
	if (((t_tok*)env.tokens->prev->data)->type != EOFTOK)
		return (cleanup(failure, &env));
	if (!parser(&env))
		return (cleanup(failure, &env));
	if (!writebin(&env))
		return (cleanup(failure, &env));
	return (cleanup(success, &env));
}
