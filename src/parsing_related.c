/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_related.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:55:26 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:15 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cor.h"

void parse_arg_dump()
{

}

void parse_arg_n(int *ac, int argc, char **argv, t_vm *vm)
{
	int i;
	int flag;
	t_gladiator *gladiator;

	if (*ac + 2 < argc && (i = -1))
	{
		if (!ft_isdigit(argv[*ac + 1][0]) || !is_number(argv[*ac + 1]))
		{
			ft_putendl_fd("Error: invalid parameters", 2);
			exit(1);
		}
		vm->n_id = ft_atoi(argv[*ac + 1]);
		(vm->n_id > vm->last_id) && (vm->last_id = vm->n_id);
		gladiator = vm->gladiators;
		flag = 0;
		while(gladiator)
		{
			if (gladiator->id == vm->n_id)
				flag = 1;
			gladiator = gladiator->next;
		}
		if (!flag && ft_strlen(argv[(*ac)++ + 1]) <= 10 && vm->n_id > 0 && vm->n_id <= MAX_PLAYERS)
			return ;
	}
	ft_putendl_fd("Error: invalid parameters", 2);
	exit(1);
}

int		get_non_exist_id(t_gladiator *head)
{
	t_gladiator *gldtor;
	int id;

	id = 1;
	while(id <= MAX_PLAYERS)
	{
		gldtor = head;
		while(gldtor)
		{
			if (gldtor->id == id)
				break;
			gldtor = gldtor->next;
		}
		if (!gldtor)
			return (id);
		id++;
	}
	return (-1);
	
}

void	parse_args(int argc, char **argv, t_vm *vm)
{
	int			ac;
	char		*cor;
	t_gladiator	*gldtor;
	t_gladiator	*gldtor_tmp;

	ac = 1;
	vm->nbr_of_gldtors = 0;
	while (ac < argc)
	{
		if (!ft_strcmp("-v", argv[ac]))
		{
			printf("flag -v\n");
			// parse_arg_verbose();
		}
		else if (!ft_strcmp("-dump", argv[ac]))
		{
			printf("flag -dump\n");
			// parse_arg_dump();// pass ac + 1
		}
		else if ((cor = ft_strstr(argv[ac], ".cor")) && cor != argv[ac] && !cor[4])
		{
			vm->nbr_of_gldtors++;
			if (vm->nbr_of_gldtors > MAX_PLAYERS)
			{
				ft_putendl_fd("Error: MAX_PLAYERS EXCEEDED", 2);
				exit(1);
			}
			if (!(gldtor = (t_gladiator *)malloc(sizeof(t_gladiator))))
				exit (1);
			ft_bzero(gldtor, sizeof(t_gladiator));
			gldtor->associated_file = argv[ac];
			get_player(gldtor, &(vm->n_id));
			gldtor->next = NULL;
			if (!vm->gladiators)
			{
				vm->gladiators = gldtor;
				vm->tail = gldtor;
			}
			else
			{
				vm->tail->next = gldtor;
				vm->tail = gldtor;
			}
		}
		else if (!ft_strcmp("-n", argv[ac]))
			parse_arg_n(&ac, argc, argv, vm);
		else
		{
			ft_putendl_fd("Error: invalid parameters", 2);
			exit(1);
		}
		ac++;
	}
	gldtor = vm->gladiators;
	vm->last_id = 1;
	while(gldtor)
	{
		if (gldtor->id > vm->nbr_of_gldtors)
		{
			ft_putendl_fd("Error: invalid id", 2);
			exit(1);
		}
		if (gldtor->id == -1)
			gldtor->id = get_non_exist_id(vm->gladiators);
		gldtor = gldtor->next;
	}
}
