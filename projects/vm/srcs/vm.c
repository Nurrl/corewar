/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/11 13:10:09 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int main(int argc, char *argv[])
{
	static t_vm	vm;

	vm.dump = -1;
	init_vm(&vm, argc, argv);
	load_players(&vm);
	sort_player_by_index(&vm);
	print_loaded_players(&vm);
	init_processes(&vm);
	exec_cycle(&vm);
	if (vm.dump == vm.cycle_count)
		print_dump(vm.memory);
	return (0);
}
