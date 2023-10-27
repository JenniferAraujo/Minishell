/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:17:02 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/27 20:17:02 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_main	*get_main(t_main	*main)
{
	static t_main	*static_main;

	if (main)
		static_main = main;
	return (static_main);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_min_len(char *str, int i)
{
	int		min;

	min = 0;
	min = get_min(ft_strclen(str + i + 1, ' '),
			ft_strclen(str + i + 1, SQUOTE));
	min = get_min(min, ft_strclen(str + i + 1, '\n'));
	min = get_min(min, ft_strclen(str + i + 1, '\t'));
	return (min);
}
