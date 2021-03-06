/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:28:31 by glodi             #+#    #+#             */
/*   Updated: 2019/05/14 13:26:17 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
# define OPCODE_H

# include "bswap.h"
# include "dump.h"
# include "flags.h"
# include "libft.h"
# include "libpf.h"
# include "proc.h"
# include "struct.h"
# include "vm_utils.h"

/*
** utils read
*/

uint32_t	read_arg(t_process *process, uint8_t *mem, int type);
uint8_t		read_octet_code(t_process *process, uint8_t *mem);
void		read_in_memory(
		uint8_t *memory, uint8_t *buffer, uint8_t len, size_t at);

/*
** utils get
*/

int			get_type_arg(uint8_t octet_code, uint8_t arg_number);
uint32_t	get_reg(t_process *process, uint8_t reg_idx);
uint32_t	get_indirect(int16_t current, int16_t relative, uint8_t *memory);
uint32_t	get_indirect_restrict(
		int16_t current, int16_t to_add, uint8_t *memory);
int			get_argument_all_restrict_4(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc);
int			get_argument_all_restrict(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc);
int			get_argument_all(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc);

/*
** utils write
*/

void		write_in_memory(
		uint8_t *mem, uint8_t *content, size_t len, size_t at);
void		write_in_registre(
		t_process *process, uint16_t reg_idx, uint32_t value);
void		write_in_mem_wrapper(
		t_vm *vm, t_process *proc, uint8_t *content, t_coord coord);

/*
** utils other
*/

uint16_t	get_restrict_address(int16_t current, int16_t plus);
uint16_t	get_address(int16_t current, int16_t plus);
/*
** command
*/

void		exec_sti(t_vm *vm, t_process *process, const t_op *op);
void		exec_live(t_vm *vm, t_process *process, const t_op *op);
void		exec_and(t_vm *vm, t_process *process, const t_op *op);
void		exec_zjump(t_vm *vm, t_process *process, const t_op *op);
void		exec_aff(t_vm *vm, t_process *process, const t_op *op);
void		exec_ld(t_vm *vm, t_process *process, const t_op *op);
void		exec_fork(t_vm *vm, t_process *process, const t_op *op);
void		exec_lfork(t_vm *vm, t_process *process, const t_op *op);
void		exec_xor(t_vm *vm, t_process *process, const t_op *op);
void		exec_or(t_vm *vm, t_process *process, const t_op *op);
void		exec_sub(t_vm *vm, t_process *process, const t_op *op);
void		exec_add(t_vm *vm, t_process *process, const t_op *op);
void		exec_lldi(t_vm *vm, t_process *process, const t_op *op);
void		exec_ldi(t_vm *vm, t_process *process, const t_op *op);
void		exec_st(t_vm *vm, t_process *process, const t_op *op);
void		exec_lld(t_vm *vm, t_process *process, const t_op *op);

#endif
