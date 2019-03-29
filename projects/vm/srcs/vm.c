/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/29 11:18:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int quit(t_vm *vm)
{
	delete_process(&vm->processes);
	disable_socket(&vm->socket);
	return (0);
}

static int init(t_vm *vm, int ac, char **av)
{
	init_vm(vm, ac, av);
	create_server_socket(&vm->socket);
	setup_server_socket(&vm->socket);
	setup_server_interface(&vm->socket);
	bind_setup_inter(&vm->socket);
	set_listen_socket(&vm->socket);
	return 0;
}

int main(int argc, char *argv[])
{
	static t_vm vm;

	init(&vm, argc, argv);
	accept_all_client(&vm.socket);
	load_players(&vm);
	sort_player_by_index(&vm);
	print_loaded_players(&vm);
	init_processes(&vm);
	make_cycle(&vm);
	print_winner(&vm);
	if (vm.dump != -1)
		print_dump(vm.memory);
	return (quit(&vm));
}
