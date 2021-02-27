/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_related.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:55:52 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:27 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cor.h"


void vm_init(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	if (!(vm->colosseum = (uint8_t *)malloc(sizeof(uint8_t) * (MEM_SIZE + 1))))
	{
		ft_putendl_fd("Failed to build the colosseum", 2);
		exit(1);
	}
	ft_bzero(vm->colosseum, sizeof(vm->colosseum));
	// vm->gladiators = NULL;
	// vm->nbr_of_gldtors = 0;
	// vm->the_conqueror = NULL;
	// vm->cursors = NULL;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->n_id = -1;
	vm->last_id = 1;
	// vm->cycles_after_check = 0;
}

void	prepare_battleground(t_vm	*vm)
{
	int			id;
	int			mem_zone;
	int			size;
	t_cursor	*cursor;

	id = 1;
	mem_zone = 0;
	size = MEM_SIZE / vm->nbr_of_gldtors;
	while (id <= vm->nbr_of_gldtors)
	{
		cursor = init_cursor(vm, id, mem_zone);
		load_cursor(&(vm->cursors), cursor);
		vm->cursors_counter++;
		mem_zone += size;
		id++;
	}
}

// p1:  p = 0
// p2:  p = 0 + 1365
// p3:  p = 1365 + 1365 = 2730
