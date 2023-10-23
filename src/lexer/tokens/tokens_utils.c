/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:32:55 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/23 14:33:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	check_valid_fd(char *str)
{
	long int	fd;

	fd = ft_long_atol(str);
	if (fd > INT_MAX)
		return (false);
	return (true);
}
