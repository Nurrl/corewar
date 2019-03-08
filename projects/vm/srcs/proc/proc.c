/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 12:13:59 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	uint8_t i;
	t_player *player;


	i = 0;
	while  (i < vm->players_count)
	{
		player = vm->players + i;
		player->processes = (t_process*)malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		player->processes_count = 1;
		player->processes->carry = 0;
		player->processes->player_id = player->id;
		player->processes->waiting = -1;
		player->processes->cursor_pos = 0;
		player->processes->cursor_start = (uint32_t)get_start_in_memory(vm, i);
		print_proc(player->processes);
		i++;
	}
}

void add_processes(t_player *player, uint16_t pc)
{
	size_t n;

	n = player->processes_count;
	player->processes
		= (t_process*)realloc(player->processes, sizeof(t_process) * n);
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	player->processes_count++;
	player->processes[n]
		= (t_process){
			.player_id = player->id,
			.cursor_pos = 0,
			.carry = 0,
			.cursor_start = pc,
			.waiting = -1,
		};
}
