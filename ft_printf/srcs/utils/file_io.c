/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:47:09 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 23:35:16 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

void	print_file(const char *src)
{
	FILE	*fp_src;
	char	c;

	fp_src = fopen(src, "r");
	c = fgetc(fp_src);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fp_src);
	}
	fclose(fp_src);
}

int		compare_files(const char *f1, const char *f2)
{
	FILE	*fp_f1;
	FILE	*fp_f2;
	char	usrc;
	char	expc;

	fp_f1 = fopen(f1, "r");
	fp_f2 = fopen(f2, "r");
	do
	{
		usrc = fgetc(fp_f1);
		expc = fgetc(fp_f2);
		if (usrc != expc)
			break;
	}
	while (expc != EOF && usrc != EOF);
	fclose(fp_f1);
	fclose(fp_f2);
	if (expc == usrc)
		return (0);
	else
		return (-1);
}
