/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:13:08 by warharra          #+#    #+#             */
/*   Updated: 2019/05/22 17:02:13 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_nbr_tetri(char *line)
{
	int		fd;
	int		size;
	char	*buffer;
	int		k;

	buffer = ft_strnew(21 * 26 + 1);
	fd = open(line, O_RDONLY);
	size = read(fd, buffer, 21 * 26);
	buffer[size] = '\0';
	close(fd);
	k = (size + 1) / 21;
	free(buffer);
	if (k * 21 != (size + 1))
		return (-1);
	return (k);
}

char		*read_piece_i(char *str, int n)
{
	int		fd;
	int		size;
	char	*buffer;
	int		i;

	i = 1;
	buffer = ft_strnew(21 + 1);
	fd = open(str, O_RDONLY);
	while (i <= n)
	{
		size = read(fd, buffer, 21);
		i = i + 1;
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

int			ft_check_number(char *line, int j, int k)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			j++;
		else if (line[i] == '.')
			k++;
		if ((i + 1) % 5 == 0)
			if (line[i] != '\n')
			{
				free(line);
				return (-1);
			}
		i++;
	}
	if (j == 4 && k == 12 && line[i - 1] == '\n')
	{
		free(line);
		return (1);
	}
	free(line);
	return (-1);
}

char		**create_tab(char *line)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	j = -1;
	k = 0;
	if ((tab = (char**)malloc(sizeof(char*) * 5)) == NULL)
		return (NULL);
	while (++j < 4)
	{
		if ((tab[j] = (char*)malloc(sizeof(char) * 5)) == NULL)
			return (NULL);
		i = -1;
		while (++i < 4)
		{
			tab[j][i] = line[k];
			k++;
		}
		tab[j][i] = '\0';
		k++;
	}
	tab[j] = NULL;
	free(line);
	return (tab);
}

char		**moove_top(char **tab, int ni, int nj)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#' && (ni != 0 || nj != 0))
			{
				tab[i - ni][j - nj] = '#';
				tab[i][j] = '.';
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (tab);
}
