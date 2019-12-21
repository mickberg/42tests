/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:35 by mikaelber         #+#    #+#             */
/*   Updated: 2019/12/21 02:45:55 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*res;

	if (argc == 2)
		res = base_convert(argv[1], 16, 8);
	else if (argc == 3)
		res = base_convert(argv[1], ft_atoi(argv[2]), 10);
	else if (argc == 4)
		res = base_convert(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		return (0);

	printf("%s", res);
	return (0);
}
