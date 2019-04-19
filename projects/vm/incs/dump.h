/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:55:19 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 18:55:07 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMP_H
# define DUMP_H

# include <libft.h>
# include <libpf.h>
# include "error.h"
# include "struct.h"
# include <errno.h>
# include <op.h>
# include <stdint.h>
# include <unistd.h>
# include "heat_map.h"

# define BYTE_PER_LINE 64
# define BYTE_PRINT_LENGTH 3
# define LINE_LENGTH BYTE_PER_LINE * BYTE_PRINT_LENGTH
# define LINE_PREFIX 8
# define NB_LINE MEM_SIZE / BYTE_PER_LINE

void		print_dump(void *mem);
void		print_memory(uint8_t *mem);
void		load_players(t_vm *vm);
void		load_player(t_vm *vm, int player_idx);
void		*get_champ_bin(t_vm *vm, int player_idx);
uint32_t	get_champ_size(t_vm *vm, int player_idx);
void		sort_player_by_index(t_vm *vm);

size_t		get_start_idx_in_memory(int player_count, int player_idx);
void		*get_start_in_memory(t_vm *vm, int player_idx);
void		*get_pos_in_memory(void *mem, t_process *process);
size_t		get_idx_in_memory(t_process *process);

#endif
