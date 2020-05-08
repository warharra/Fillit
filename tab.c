/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:48:05 by warharra          #+#    #+#             */
/*   Updated: 2019/05/22 16:57:50 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			***ft_malloc_tableau(char *line, int size)
{
	char		***grille;
	int			k;
	int			i;

	if (!(grille = (char***)malloc(sizeof(char **) * size + 1)))
		return (NULL);
	k = 0;
	while (k < size)
	{
		grille[k] = ft_add_letter(ft_give_tab(line, k + 1), k + 1);
		k++;
	}
	grille[k] = NULL;
	return (grille);
}

int				ft_len_tab(char **map)
{
	int			n;

	n = 0;
	while (map[n])
		n = n + 1;
	return (n);
}

int				ft_sqrt(int nb)
{
	int		count;

	count = 0;
	while (count * count < nb)
		count++;
	if (count * count == nb)
		return (count);
	else
		return (ft_sqrt(nb + 1));
	return (0);
}

void			ft_place(char *line)
{
	int		i;
	int		size;
	char	**map;
	char	***tab;
	int		position;

	position = 0;
	tab = ft_malloc_tableau(line, ft_nbr_tetri(line));
	size = ft_sqrt(ft_nbr_tetri(line) * 4);
	map = ft_malloc_tab(size);
	i = 1;
	while (ft_solve_tetri(map, tab, position, i) == 0)
	{
		ft_free(map, size);
		size = size + 1;
		position = 0;
		map = ft_malloc_tab(size);
		i = 1;
	}
	print(map, size);
	ft_free(map, size);
	ft_free_tab(tab, ft_nbr_tetri(line));
}

int				ft_solve_tetri(char **map, char ***tab, int p, int i)
{
	static int	tab_pos[26];
	int			size;

	size = ft_len_tab(map);
	if (i <= 0)
		return (0);
	if (tab[i - 1] == 0)
		return (1);
	while ((p < (size * size)) &&
				(ft_place_i_tetri(map, tab[i - 1], p / size, p % size) == -1))
		p++;
	if (p == (size * size))
		return (0);
	tab_pos[i] = p;
	map = ft_place_it_then(map, tab[i - 1], p / size, p % size);
	if (ft_solve_tetri(map, tab, 0, i + 1) == 1)
		return (1);
	else
	{
		map = ft_delete_i_letter(map, size, i);
		return (ft_solve_tetri(map, tab, (tab_pos[i] + 1), i));
	}
	return (0);
}
