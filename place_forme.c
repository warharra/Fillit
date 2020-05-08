/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_forme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:14:23 by alperrin          #+#    #+#             */
/*   Updated: 2019/05/22 17:12:07 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_malloc_tab(unsigned int size)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	if ((tab = (char**)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
	while (j < size)
	{
		if ((tab[j] = (char*)malloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		i = 0;
		while (i < size)
		{
			tab[j][i] = '.';
			i = i + 1;
		}
		tab[j][i] = '\0';
		j = j + 1;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_add_letter(char **file, int n)
{
	char	letter;
	int		i;
	int		j;

	letter = 'A' + n - 1;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (file[i][j] == '#')
			{
				file[i][j] = letter;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (file);
}

int			ft_place_i_tetri(char **map, char **tetri, int i, int j)
{
	int		l;
	int		size;
	int		c;

	size = ft_len_tab(map);
	l = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tetri[l][c] != '.')
			{
				if ((i + l > size - 1) || (j + c > size - 1))
					return (-1);
				if ((tetri[l][c] != '.') && (map[i + l][j + c] != '.'))
					return (-1);
			}
			c = c + 1;
		}
		l = l + 1;
	}
	return (1);
}

char		**ft_place_it_then(char **map, char **tetri, int i, int j)
{
	int		l;
	int		c;
	int		size;

	size = ft_len_tab(map);
	l = 0;
	c = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tetri[l][c] != '.')
				map[i + l][j + c] = tetri[l][c];
			c = c + 1;
		}
		l = l + 1;
	}
	return (map);
}

char		**ft_delete_i_letter(char **map, int size, int n)
{
	char	letter;
	int		j;
	int		k;

	letter = 'A' + n - 1;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			if (map[j][k] == letter)
				map[j][k] = '.';
			k = k + 1;
		}
		j = j + 1;
	}
	return (map);
}
