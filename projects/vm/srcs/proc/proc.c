/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 11:57:42 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

#define SET_OR_START 1

static int g_id = 0;

void	init_processes(t_vm *vm)
{
	int		i;
	size_t	start;
	int32_t	player_id;

	i = 0;
	vm->processes = NULL;
	vm->processes_count = vm->players_count;
	while (i < vm->players_count)
	{
		start = get_start_idx_in_memory(
				vm->players_count, vm->sorted_players_idx[i]);
		player_id = vm->players[vm->sorted_players_idx[i]].id;
		init_process(&vm->processes, start, player_id);
		i++;
	}
}

void	init_process(t_process **head, uint16_t cursor_start, int32_t player_id)
{
	t_process *proc;

	errno = 0;
	proc = (t_process *)malloc(sizeof(t_process));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	ft_memset(proc, 0, sizeof(t_process));
	proc->exec_cycle = -1;
	proc->cursor_start = cursor_start;
	proc->player_id = player_id;
	proc->regs[0] = player_id;
	proc->next = (*head);
	proc->id = g_id;
	g_id++;
	*head = proc;
	DEBUG_PROC && print_proc(proc);
}

void	delete_process(t_process **head)
{
	t_process *node;
	t_process *tmp;

	if (!head || !*head)
		return ;
	node = *head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*head = NULL;
}

void	copy_process(t_vm *vm, t_process *process, size_t pos)
{
	t_process *dup;

	errno = 0;
	dup = (t_process *)malloc(sizeof(t_process));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	ft_memcpy(dup, process, sizeof(t_process));
	if (SET_OR_START)
		dup->cursor_pos = pos;
	else
	{
		dup->cursor_start = pos;
		dup->cursor_pos = 0;
	}
	vm->processes_count++;
	dup->next = vm->processes;
	dup->id = g_id;
	g_id++;
	dup->exec_cycle = -1;
	vm->processes = dup;
}
