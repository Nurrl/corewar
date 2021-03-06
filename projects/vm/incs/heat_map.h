/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:34:22 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 13:24:44 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAT_MAP_H
# define HEAT_MAP_H

# include "libpf.h"
# include "libft.h"
# include "struct.h"
# include "flags.h"
# include <unistd.h>

void	assign_player_to_area(
		uint8_t *heat_map, int player_idx, size_t at, size_t len);
void	dump_heat_map(uint8_t *heat_map);

#endif
