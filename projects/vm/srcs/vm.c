/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/13 11:20:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int main(int argc, char *argv[])
{
	static t_vm	vm;

	init_vm(&vm, argc, argv);
	load_players(&vm);
	sort_player_by_index(&vm);
	print_loaded_players(&vm);
	init_processes(&vm);
	make_cycle(&vm);
	if (vm.dump != -1)
		print_dump(vm.memory);
	return (0);
}
