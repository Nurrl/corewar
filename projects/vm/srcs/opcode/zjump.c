/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:49:37 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 12:00:59 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void	exec_zjump(t_vm *vm, t_process *process, const t_op *op)
{
	int16_t		move_to;
	uint16_t	pos;

	(void)op;
	pos = process->cursor_pos - 1;
	move_to = read_arg(process, vm->memory, T_DIR);
	if (process->carry == 1)
	{
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "zjmp :(%hx + %hx = %hx)\n",
				pos, move_to, get_address(pos, move_to));
		process_set_cursor_pos(process, get_address(pos, move_to));
	}
	else
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "zjump skip\n");
}
