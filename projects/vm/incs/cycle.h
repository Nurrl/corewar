/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:52 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 10:20:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_H
# define CYCLE_H

# include "struct.h"
# include <unistd.h>
# include <stdlib.h>
# include "flags.h"
# include "proc.h"

void		exec_process(t_vm *vm, t_process *process);
const t_op	*get_opcode(uint8_t val);
void		make_cycle(t_vm *vm);
void		set_jump_to(t_vm *vm, int64_t exec_cycle);
int			setup_next_exec(
	t_vm *vm, t_process *process, const t_op *op, off_t off);

#endif
