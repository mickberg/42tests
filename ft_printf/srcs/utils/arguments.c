/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:54:06 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/13 14:47:26 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

static int	set_opt(char c, t_testinfo *info)
{
	char	opts[256];

	ft_bzero(opts, 256);
	opts['p'] = OFLAG_PRINT;
	opts['P'] = OFLAG_PRINTALL;
	opts['o'] = OFLAG_PRINT_OUTPUT;
	opts['l'] = OFLAG_LEAKS;
	if (!opts[(int)c])
		return (0);
	info->opts |= opts[(int)c];
	return (1);
}

int			get_arguments(int argc, char **argv, t_testinfo *info)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j] != '\0')
		{
			if (!set_opt(argv[i][j], info))
			{
				ft_printf("ft_printf_test illegal option -- %c\n", argv[i][j]);
				ft_printf("%s\n", USAGE);
				return (0);
			}
			++j;
		}
		++i;
	}
	info->opts & OFLAG_PRINTALL && (info->opts &= ~OFLAG_PRINT);
	return (1);
}
