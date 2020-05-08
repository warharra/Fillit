/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:46:18 by warharra          #+#    #+#             */
/*   Updated: 2019/05/22 17:43:06 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free(char **map, int size)
{
	int		i;

	i = 0;
	while (i < (size + 1))
	{
		free(map[i]);
		i = i + 1;
	}
	free(map);
}

void		ft_usage(char **av)
{
	ft_putstr("usage: ");
	ft_putstr(av[0]);
	ft_putstr(" filename");
	write(1, "\n", 1);
}

void		ft_free_tab(char ***tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (size))
	{
		ft_free(tab[i], 4);
		i = i + 1;
	}
	free(tab);
}

void		print(char **map, int size)
{
	int		j;
	int		k;

	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			ft_putchar(map[j][k]);
			k = k + 1;
		}
		ft_putchar('\n');
		j = j + 1;
	}
}

int			main(int argc, char **argv)
{
	int		i;
	int		size;
	char	**map;
	char	***tab;
	int		position;

	position = 0;
	if (argc != 2)
		ft_usage(argv);
	else if (check_final(argv[1]) == -1)
		ft_putstr("error\n");
	else
		ft_place(argv[1]);
	return (0);
}
