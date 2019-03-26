/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/26 16:45:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "libpf.h"

void setup_next_cycle(t_vm *vm)
{
	vm->nb_live_for_cycle = 0;
	vm->next_check = vm->cycle_count + vm->cycle_to_die;
}

void check_cycle(t_vm *vm)
{
	if (vm->next_check == vm->cycle_count)
	{
		if (vm->nb_live_for_cycle >= NBR_LIVE || vm->nb_check >= MAX_CHECKS)
		{
			vm->nb_check = 1;
			vm->cycle_to_die -= CYCLE_DELTA;
		}
		else
			vm->nb_check++;
		filter_process_have_live(vm);
		setup_next_cycle(vm);
	}
}

void exec_cycle(t_vm *vm)
{
	t_process *process;

	process = vm->processes;
	while (process)
	{
		exec_process(vm, process);
		process = process->next;
	}
	check_cycle(vm);
	vm->cycle_count++;
}

void cycle_until_death(t_vm *vm)
{
	while (vm->processes_count > 0 && vm->cycle_to_die > 0)
	{
		exec_cycle(vm);
	}
}

void cycle_until_dump(t_vm *vm)
{
	while (vm->cycle_count < vm->dump && vm->processes_count > 0 &&
		   vm->cycle_to_die > 0)
	{
		exec_cycle(vm);
	}
}

void make_cycle(t_vm *vm)
{
	if (vm->dump == -1)
		cycle_until_death(vm);
	else
		cycle_until_dump(vm);
}
