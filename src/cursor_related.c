/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:54:26 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:23:54 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cor.h"

void	load_cursor(t_cursor **curs_list, t_cursor *new_curs)
{
	if (new_curs)
		new_curs->next = *curs_list;
	*curs_list = new_curs;
}

t_cursor	*init_cursor(t_vm *vm, int id, int mem_zone)
{
	t_cursor	*cursor;
	t_gladiator *gldtor;

	if (!(gldtor = get_gldtor_by_id(vm->gladiators, id)))
	{
		ft_putstr("gladiator doesn't exist\n");
		//free
		exit(0);
	}
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
	{
		// free
		exit(0);
	}
	ft_bzero(cursor, sizeof(t_cursor));
	ft_memcpy(&(vm->colosseum[mem_zone]), gldtor->exec_code, gldtor->exec_code_size);

	cursor->id = id;
	cursor->carry = FALSE;
	cursor->current_addr = mem_zone;
	cursor->last_live = 0;
	cursor->wait_cycles = 0;
	cursor->jump = 0;
	cursor->reg[0] = id * (-1); // re-check this after
	cursor->is_alive = FALSE;
	return (cursor);
}

