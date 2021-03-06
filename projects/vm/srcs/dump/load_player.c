/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:48:50 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 15:05:58 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

void		load_players(t_vm *vm)
{
	int	i;

	i = -1;
	while (++i < vm->players_count)
		load_player(vm, i);
}

void		load_player(t_vm *vm, int player_idx)
{
	void		*champ_bin;
	uint32_t	champ_size;
	uint8_t		*start_in_memory;

	champ_bin = vm->players[player_idx].file_buffer + sizeof(t_header);
	champ_size = get_champ_size(vm, player_idx);
	if (champ_size > (uint32_t)CHAMP_MAX_SIZE)
		set_errno_exit(EFBIG, vm->players[player_idx].file_name);
	start_in_memory = get_start_in_memory(vm, player_idx);
	ft_memcpy(start_in_memory, champ_bin, champ_size);
	assign_player_to_area(
		vm->heat_map, player_idx, start_in_memory - vm->memory, champ_size);
}

uint32_t	get_champ_size(t_vm *vm, int player_idx)
{
	return ((uint32_t)vm->players[player_idx].header.prog_size);
}

void		*get_start_in_memory(t_vm *vm, int player_idx)
{
	return (
		vm->memory + get_start_idx_in_memory(vm->players_count, player_idx));
}

size_t		get_start_idx_in_memory(int player_count, int player_idx)
{
	return ((MEM_SIZE / player_count) * player_idx);
}
