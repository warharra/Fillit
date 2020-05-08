/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warharra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:53:42 by warharra          #+#    #+#             */
/*   Updated: 2019/05/22 17:04:22 by warharra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	**moove_top(char **tab, int ni, int nj);
char	**ft_give_tab(char *s, int i);
int		top_j(int *line);
int		top_i(int *line);
int		ft_nbr_tetri(char *line);
void	ft_bzero_int(int *s, size_t n);
int		*describe_form(char **ptr);
int		check_form(int *pos);
int		check_form2(int *pos);
int		ft_check_number(char *line, int j, int k);
char	**create_tab(char *line);
int		check_r(char *tab);
char	*read_piece_i(char *file, int n);
int		check_final(char *s);
char	**ft_add_letter(char **file, int i);
int		ft_place_i_tetri(char **map, char **tetri, int i, int j);
char	**ft_place_it_then(char **map, char **tetri, int i, int j);
char	**ft_delete_i_letter(char **map, int size, int n);
int		ft_solve_tetri(char **map, char ***tetri, int position, int i);
int		ft_nb_letter(char **map, int i, int size);
char	**ft_malloc_tab(unsigned int size);
char	***ft_malloc_tableau(char *line, int size);
char	***ft_tableau_tetri(char *file);
int		ft_len_tab(char **tab);
void	print(char **map, int size);
void	ft_free(char **map, int size);
int		ft_sqrt(int nb);
void	ft_free_tab(char ***tab, int size);
void	ft_place(char *line);

#endif
