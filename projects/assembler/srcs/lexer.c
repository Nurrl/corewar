/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:52:04 by lroux             #+#    #+#             */
/*   Updated: 2019/05/20 13:53:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <lift/string.h>
#include <lift/memory.h>
#define INSIDE
#include "lexer.h"

static const t_lexmap	g_lexmap[128] = {
	{COMMENT_CHAR, COMMNTMARK},
	{LABEL_CHAR, LBLMARK},
	{DIRECT_CHAR, DIRMARK},
	{COMMAND_CHAR, CMDMARK},
	{SEPARATOR_CHAR, SEP},
	{'"', QUOTE},
	{'\n', NL},
	{'\0', 0}
};

static char		*getfile(t_asm *env, char *name)
{
	ssize_t	filelen;
	char	*content;
	int		fd;

	env->slen = ft_strlen(name);
	if (env->slen < 3 || !ft_strequ(&name[env->slen - 2], ".s"))
		return ((void*)(long)!perr(3, name, env->self));
	env->sname = name;
	if ((fd = open(env->sname, O_RDONLY)) == -1)
		return ((void*)(long)!perr(2, name, strerror(errno)));
	if ((filelen = lseek(fd, 0, SEEK_END)) < 1 || lseek(fd, 0, SEEK_SET) != 0
			|| filelen > MAX_FILEIN)
		return ((void*)(long)!perr(4, name));
	if (!(content = ft_calloc(filelen + 5, sizeof(*content))))
		return (NULL);
	if (read(fd, content, filelen) != filelen)
		return ((void*)(long)!perrfree(content, 5, name, strerror(errno)));
	close(fd);
	ft_strcpy(content + filelen + 1, "EOF");
	if (!(env->scstring = ft_strndup(content, filelen)))
		return (NULL);
	ft_strrep((char*)env->scstring, '\t', ' ');
	if ((ssize_t)ft_strlen(content) != filelen)
		env->isbinary = true;
	return (content);
}

static t_tok	*newtok(t_asm *env, int type, char *val, size_t len)
{
	t_tok	*tok;

	if (!(tok = ft_calloc(1, sizeof(*tok))))
		return (NULL);
	tok->type = type;
	tok->val = ft_strndup(val, len);
	tok->pos = val - env->sstring;
	tok->y = ft_strncc(env->scstring, tok->pos, '\n') + 1;
	tok->x = tok->pos - ft_strncspn(env->scstring, tok->y - 1, "\n")
		+ ((tok->y - 1) ? 0 : 1);
	tok->ls = (char*)env->scstring + (tok->pos - tok->x) + 1;
	tok->ll = ft_strcspn(tok->ls, "\n");
	return (tok);
}

static void		lexlitteral(t_asm *env, t_node **toks, char *tok)
{
	size_t validlen;

	if (!*tok)
		return ;
	validlen = ft_strspn(tok, LITTERALCHARS);
	if (*(tok + validlen))
	{
		if (validlen)
			ll_add(toks, newtok(env, LITTERAL, tok, validlen));
		lextok(env, toks, tok + validlen, true);
	}
	else
		ll_add(toks, newtok(env, LITTERAL, tok, ft_strlen(tok)));
}

static t_bool	lextok(t_asm *env, t_node **toks, char *tok, t_bool nolitteral)
{
	size_t	z;

	if (!tok)
		return (false);
	z = -1;
	while (g_lexmap[++z].id)
	{
		if (*tok == g_lexmap[z].id)
		{
			ll_add(toks, newtok(env, g_lexmap[z].type, tok, 1));
			lextok(env, toks, tok + 1, false);
			return (true);
		}
	}
	if (nolitteral)
		ll_add(toks, newtok(env, UNKNOWN, tok, 1));
	else
	{
		lexlitteral(env, toks, tok);
		return (true);
	}
	lextok(env, toks, tok + 1, false);
	return (true);
}

t_node			*lexer(t_asm *env, char *name)
{
	char	*tok;
	char	*file;
	t_node	*toks;

	toks = 0;
	if (!(file = getfile(env, name)))
		return (NULL);
	env->sstring = file;
	tok = ft_strtok(file, "\t\v\f\r ");
	while (lextok(env, &toks, tok, false))
		tok = ft_strtok(NULL, "\t\v\f\r ");
	ll_add(&toks, newtok(env, EOFTOK, file + ft_strlen(env->scstring) + 1, 3));
	((t_tok*)toks->prev->data)->ll = ((t_tok*)toks->prev->prev->data)->ll;
	((t_tok*)toks->prev->data)->ls = ((t_tok*)toks->prev->prev->data)->ls;
	((t_tok*)toks->prev->data)->x = ((t_tok*)toks->prev->prev->data)->x;
	((t_tok*)toks->prev->data)->y = ((t_tok*)toks->prev->prev->data)->y;
	((t_tok*)toks->prev->data)->pos = ((t_tok*)toks->prev->prev->data)->pos;
	free(env->sstring);
	env->sstring = NULL;
	if ((toks && ((t_tok*)toks->data)->type == EOFTOK) || env->isbinary)
		env->isbinary = perr(22, env->sname);
	return (toks);
}
