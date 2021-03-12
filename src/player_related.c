/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:55:36 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:19 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cor.h"

t_gladiator *get_gldtor_by_id(t_gladiator *gldtor_lst, int id)
{
	while (gldtor_lst)
	{
		if (gldtor_lst->id == id)
			return (gldtor_lst);
		gldtor_lst = gldtor_lst->next;
	}
	return (NULL);
}

void		get_player(t_gladiator *gldtor, int *n_id)
{
	int		fd;
	u_int32_t	size;
	u_int8_t	buffer[4096];

	gldtor->id = -1;
	if ((fd = open(gldtor->associated_file, O_RDONLY)) < 0)
	{
		ft_putstr_fd(gldtor->associated_file, 2);
		ft_putendl_fd(" is an Invalid file.", 2);
		exit(1);
	}
	if (read(fd, &buffer, HEADER_SIZE) < HEADER_SIZE)
	{
		ft_putstr_fd(gldtor->associated_file, 2);
		ft_putendl_fd(" has an Invalid header.", 2);
		exit(1);
	}
	if (*(u_int32_t *)buffer != little_to_big_endian(COREWAR_EXEC_MAGIC))
	{
		ft_putstr_fd(gldtor->associated_file, 2);
		ft_putendl_fd(" has an invalid magic Header.", 2);
		exit(1);
	}
	ft_memcpy((void*)(gldtor->prog_name), buffer + 4 , PROG_NAME_LENGTH);
	ft_memcpy((void*)(gldtor->comment), buffer + 4 + PROG_NAME_LENGTH + 8, COMMENT_LENGTH + 1);
	if ((size = read(fd, &buffer, CHAMP_MAX_SIZE + 1)) <= 0)
	{
		ft_putstr_fd(gldtor->associated_file, 2);
		ft_putendl_fd(" is a champion without executable code", 2);
		exit(1);
	}
	if (size > CHAMP_MAX_SIZE)
	{
		ft_putendl_fd("Executable code size exceed", 2);
		exit(1);
	}
	if (*n_id > 0)
	{
		gldtor->id = *n_id;
		*n_id = -1;
	}
	gldtor->exec_code_size = size;
	ft_memcpy(gldtor->exec_code , buffer, gldtor->exec_code_size);
	close(fd);
}
