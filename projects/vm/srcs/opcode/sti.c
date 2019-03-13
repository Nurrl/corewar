/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:27:51 by glodi             #+#    #+#             */
/*   Updated: 2019/03/13 13:09:04 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_sti_arg(
	uint8_t *memory, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t type_arg;

	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, memory, T_REG));
	else
		return -1;

	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[1] = read_arg(process, memory, T_IND);
	else
		return -1;

	type_arg = get_type_arg(oc, 2);
	if (type_arg == T_REG)
		args[2] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[2] = read_arg(process, memory, T_IND);
	else
		return -1;
	return 0;
}

void exec_sti(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	size_t   pos;
	uint32_t args[3];
	uint16_t adr;

	(void)op;
	ft_bzero(args, sizeof(args));
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	if (read_sti_arg(vm->memory, process, args, oc) == -1 ||
		(adr = args[1] + args[2]) == 0)
	{
		process->carry = 1;
	}
	else
		write_in_memory(vm->memory, (uint8_t*)&args, sizeof(args[0]), pos + adr % IDX_MOD);
}
