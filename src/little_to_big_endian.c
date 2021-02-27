/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_to_big_endian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:43:26 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:03 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cor.h"

uint32_t	little_to_big_endian(uint32_t x);
uint32_t    swap_uint32(uint32_t d);
uint32_t    other_method(uint32_t a);


uint32_t little_to_big_endian(uint32_t x)
{
	return (  ((x >> 24) & 0x000000ff)
			| ((x >> 8) & 0x0000ff00)
			| ((x << 8) & 0x00ff0000)
			| ((x << 24) & 0xff000000));
}

uint32_t	swap_uint32(uint32_t d)
{
	return (  (d & 0x000000ff) << 24
			| (d & 0x0000ff00) << 8
			| (d & 0x00ff0000) >> 8
			| (d & 0xff000000) >> 24);
}

uint32_t    other_method(uint32_t a)
{
	a = ((a & (0x0000FFFF)) << 16) | ((a & (0xFFFF0000)) >> 16);
	a = ((a & (0x00FF00FF)) << 8) | ((a & (0xFF00FF00)) >> 8);
	return a;
}

// int main( )
// {
// 	int Little_Endian = 0xAABBCCDD ;

// 	printf("\n Little_Endian = %d\n", Little_Endian);

// 	printf("\n Little_Endian = 0x%X\n", Little_Endian);

// 	printf("\n Big_Endian    = 0x%X\n", little_to_big_endian(Little_Endian));

// 	printf("\n Big_Endian    = 0x%X\n", swap_uint32(Little_Endian));

// 	printf("\n Big_Endian    = 0x%X\n", other_method(Little_Endian));
// }
