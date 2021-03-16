/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:44:08 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/02 11:44:19 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COR_H
# define COR_H

# include <stdlib.h>
# include "op.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h> // ************* delete
# include <unistd.h>


#define HEADER_SIZE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

typedef enum			e_boolean
{
	FALSE,
	TRUE,
}						t_boolean;

typedef struct			s_gladiator
{
	int					id;
	char				*associated_file;
	char				prog_name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				exec_code[MEM_SIZE];
	u_int32_t			exec_code_size;
	struct s_gladiator	*next;
}						t_gladiator;

typedef struct	 		s_cursor
{
	int					id;
	u_int32_t			current_addr;
	t_boolean			carry;
	int					op_code; // operation code
	int					last_live;
	int					wait_cycles;
	int					jump;
	int					reg[REG_NUMBER];	// register
	// t_gladiator		*gladiator; // not needed
	t_boolean			is_alive;
	struct s_cursor		*next;
}						t_cursor;

typedef struct s_op
{
	char				*op_name;
	int					arg_len;
	int					arg[3];
	int					op_code;
	int					cycles_to_wait;
	char				*description;
	int					codage_octect;
	int					size_t_dir;
}						t_op;

extern t_op    op_tab[17];

typedef struct			s_vm
{
	u_int8_t				*colosseum;
	t_gladiator			*gladiators;
	t_gladiator			*tail;
	int					nbr_of_gldtors;
	int					n_id;
	int					last_id;
	t_gladiator			*the_conqueror;//   last_survivor
	t_cursor			*cursors; // list of process/cursors
	int					cursors_counter;
	int					lives_num;
	int					cycles;
	int					cycles_to_die;
	int					cycles_last_check;
	int					count_live_checks;
	int					lives_counter;
}						t_vm;

u_int32_t				little_to_big_endian(unsigned int x);
void					vm_init(t_vm *vm);
void					parse_args(int argc, char **argv, t_vm *vm);
void					get_player(t_gladiator *gldtor, int *n_id);
t_gladiator				*get_gldtor_by_id(t_gladiator *gldtor_lst, int id);
t_cursor				*init_cursor(t_vm *vm, int id, int mem_zone);
void					load_cursor(t_cursor **curs_list, t_cursor *new);
void					prepare_battleground(t_vm	*vm);
void					let_the_game_begin(t_vm *vm);





#endif
