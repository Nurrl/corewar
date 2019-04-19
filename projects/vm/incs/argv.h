/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:06:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/01 10:01:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
#define ARGV_H

#include <libpf.h>
#include <libft.h>
#include "struct.h"
#include <bswap.h>
#include <debug.h>
#include <error.h>
#include <utils.h>

#define DUMP_OPT "--dump"
#define DUMP_HELP                                                              \
	DUMP_OPT " [number] - dump the ram on stdout when the game is finished or when the "   \
	"cycle `number` is reached\n"

#define N_OPT "-n"
#define N_HELP N_OPT " [n] [champs] - set the id `n` to the player `champs`\n"

#define HEAT_OPT "--heat"
#define HEAT_HELP HEAT_OPT " - dump the heat map at the end\n"

#define SOCKET_OPT "--socket"
# define SOCKET_HELP SOCKET_OPT " [ip] [port] - open a socket at ip [ip] on port [port]\n"

#define H_OPT "-h"
#define H_HELP H_OPT " - show this usage and exit\n"

#define COMP_OPT "--counter"
#define COMP_HELP COMP_OPT " - disable jump counter"

/*
** Init functions
*/

void ft_usage(void);

void handle_option(t_vm *vm, const int argc, char **argv, int *index);

void init_player(t_vm *vm, char *binary_path, int player_id);

void init_default_ids(t_player *players, int players_count);
int  is_unique_id(t_player *players, int players_count, int id);

#endif
