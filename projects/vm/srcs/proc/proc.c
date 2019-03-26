/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/26 13:17:13 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	int		i;
	size_t  start;
	int32_t player_id;

	i = 0;
	vm->processes =
		(t_process *)ft_calloc(vm->players_count, sizeof(t_process));
	if_errno_printerr_exit(ERR_PROC_MALL);
	vm->processes_count = vm->players_count;
	while (i < vm->players_count)
	{
		start = get_start_idx_in_memory(vm->players_count, i);
		player_id = vm->players[vm->sorted_players_idx[i]].id;
		init_process(vm, start, i, player_id);
		i++;
	}
}

void init_process(t_vm *vm, uint16_t cursor_start, int index, int32_t player_id)
{
	vm->processes[index].carry = 0;
	vm->processes[index].have_live = 0;
	vm->processes[index].exec_cycle = -1;
	vm->processes[index].cursor_pos = 0;
	vm->processes[index].cursor_start = cursor_start;
	vm->processes[index].player_id = player_id;
	vm->processes[index].regs[0] = player_id;
}

void add_process(t_vm *vm, uint16_t pc, int player_id)
{
	size_t	 n;
	t_process *proc;

	n = vm->processes_count;
	vm->processes =
		(t_process *)realloc(vm->processes, sizeof(t_process) * (n + 1));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	vm->processes_count++;
	proc = vm->processes + n;
	ft_printf("%p\n", proc);
	proc->player_id = player_id;
	proc->cursor_pos = 0;
	proc->taunt_buffer[0] = 0;
	proc->taunt_size = 0;
	proc->carry = 0;
	proc->exec_cycle = -1;
	proc->cursor_start = pc;
}

void copy_process(t_vm *vm, t_process *process, size_t pos)
{
	size_t	 n;
	t_process *proc;
	t_process *nlist;

	n = vm->processes_count;
	ft_dprintf(
		2, "p:%p n:%zu l:%zu\n", vm->processes, n, sizeof(t_process) * (n + 1));
	errno = 0;
	nlist = (t_process *)malloc(sizeof(t_process) * (n + 1));
	memcpy(nlist, vm->processes, sizeof(t_process) * (n));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	proc = nlist + n;
	memcpy(proc, process, sizeof(t_process));
	proc->cursor_pos = pos;
	print_proc(process);
	print_proc(proc);
	free(vm->processes);
	// vm->processes_count++;
	vm->processes = nlist;
}
