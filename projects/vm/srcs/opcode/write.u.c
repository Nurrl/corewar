/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:26:13 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 12:02:41 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heat_map.h"
#include "opcode.h"
#include "socket.h"

void	write_in_memory(uint8_t *mem, uint8_t *content, size_t len, size_t at)
{
	size_t	i;

	i = 0;
	DEBUG_WRITE && ft_dprintf(2, WRITE_MEM, at, len, *(uint32_t *)content);
	while (i < len)
	{
		mem[(at + i) % MEM_SIZE] = content[i];
		i++;
	}
}

void	write_in_registre(t_process *process, uint16_t reg_idx, uint32_t value)
{
	if (reg_idx < 1 || reg_idx > REG_NUMBER)
	{
		DEBUG_WRITE && ft_dprintf(2, WRITE_REG_NOT, reg_idx - 1);
		return ;
	}
	DEBUG_WRITE && ft_dprintf(2, WRITE_REG, reg_idx - 1, value);
	process->regs[reg_idx - 1] = value;
}

void	write_in_mem_wrapper(
	t_vm *vm, t_process *proc, uint8_t *content, t_coord coord)
{
	size_t		at;
	t_player	*player;

	at = coord.at;
	write_in_memory(vm->memory, content, coord.len, at);
	if (vm->players_count == 1)
		assign_player_to_area(vm->heat_map, 0, at, coord.len);
	else
	{
		player = find_player(vm->players, vm->players_count, proc->player_id);
		if (player)
			assign_player_to_area(
					vm->heat_map, player - vm->players, at, coord.len);
	}
	send_mem_chunk(vm, at, coord.len);
	send_map_chunk(vm, at, coord.len);
	DEBUG_CHANGE && print_memory(vm->memory, vm->heat_map);
}
