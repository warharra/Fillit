/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_initialise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:45:24 by alperrin          #+#    #+#             */
/*   Updated: 2019/05/22 17:02:57 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_final(char *s)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	if (ft_nbr_tetri(s) < 1)
		return (-1);
	while (i <= ft_nbr_tetri(s))
	{
		if (check_form(describe_form(create_tab(read_piece_i(s, i))))
				+ check_form2(describe_form(create_tab(read_piece_i(s, i))))
				+ ft_check_number((read_piece_i(s, i)), j, k) != 3)
			return (-1);
		i = i + 1;
	}
	return (0);
}

char	**ft_give_tab(char *s, int i)
{
	return (moove_top(create_tab(read_piece_i(s, i)),
				top_j(describe_form(create_tab(read_piece_i(s, i)))),
				top_i(describe_form(create_tab(read_piece_i(s, i))))));
}

int		top_j(int *line)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (i < 4 && line[i] == 0)
	{
		n = n + 1;
		i = i + 1;
	}
	while (i < 4 && n != 0)
	{
		line[i - n] = line[i];
		line[i] = 0;
		i = i + 1;
	}
	free(line);
	return (n);
}

int		top_i(int *line)
{
	int i;
	int n;

	n = 0;
	i = 4;
	while (i < 8 && line[i] == 0)
	{
		n = n + 1;
		i = i + 1;
	}
	while (i < 8 && n != 0)
	{
		line[i - n] = line[i];
		line[i] = 0;
		i = i + 1;
	}
	free(line);
	return (n);
}
