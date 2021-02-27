/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_game_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:23:32 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:00 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cor.h"

void	exec_operation()
{

}

void	check_who_is_alive()
{

}

void loop_through_cursors(t_vm *vm)
{
	t_cursor	*cursor;
	int			adr;
	int			op_code;

	cursor = vm->cursors;
	while (cursor)
	{
		// convert from hexa to int
		adr = cursor->current_addr;//vm->colosseum[cursor->current_addr];
		if (adr && adr <= REG_NUMBER)
		{
			if (cursor->wait_cycles == -1)
				cursor->wait_cycles = op_tab[op_code].cycles_to_wait;
			if (!cursor->wait_cycles)
				exec_operation();
			else
				cursor->wait_cycles--;
		}
		else
			cursor->current_addr++;
		cursor = cursor->next;
	}
}

void	performe_check(t_vm *vm)
{
	if ((vm->cycles == vm->cycles_last_check + vm->cycles_to_die) || vm->cycles_to_die <= 0)
	{
		vm->cycles_last_check = vm->cycles;
		vm->count_live_checks++;
		check_who_is_alive();
		if (vm->lives_counter >= NBR_LIVE || vm->count_live_checks == MAX_CHECKS)
		{
			vm->count_live_checks = 0;
			vm->lives_counter = 0;
			vm->cycles_to_die -= CYCLE_DELTA;
		}
	}
}

void let_the_game_begin(t_vm *vm)
{
	while (++vm->cycles)
	{
		loop_through_cursors(vm);
		performe_check(vm);

		if (vm->cycles == 100)
		{
			printf("100 cycles \n");
			exit(0);
		}
	}
}
