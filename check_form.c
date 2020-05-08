/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:13:26 by warharra          #+#    #+#             */
/*   Updated: 2019/05/22 17:00:06 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero_int(int *s, size_t n)
{
	int	*tmp;
	int	i;

	tmp = s;
	i = 0;
	while (i < (int)n)
	{
		tmp[i] = 0;
		i = i + 1;
	}
}

int		*describe_form(char **tab)
{
	int	i;
	int	j;
	int	*pos;

	if ((pos = (int*)malloc(sizeof(int) * 9)) == NULL)
		return (0);
	ft_bzero_int(pos, 8);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				pos[i] = 1;
				pos[j + 4] = 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
	ft_free(tab, 4);
	return (pos);
}

int		check_form(int *pos)
{
	int i;

	i = 0;
	while (i <= 1)
	{
		if (pos[i] == 1 && pos[i + 1] == 0 && (pos[i + 2] == 1 || pos[3] == 1))
		{
			free(pos);
			return (0);
		}
		i = i + 1;
	}
	i = 4;
	while (i <= 5)
	{
		if (pos[i] == 1 && pos[i + 1] == 0 && (pos[i + 2] == 1 || pos[7] == 1))
		{
			free(pos);
			return (0);
		}
		i = i + 1;
	}
	free(pos);
	return (1);
}

int		check_form2(int *pos)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (i < 8)
	{
		if (pos[i] == 1)
			res = res + 1;
		i = i + 1;
	}
	if (res > 5)
	{
		free(pos);
		return (0);
	}
	free(pos);
	return (1);
}
