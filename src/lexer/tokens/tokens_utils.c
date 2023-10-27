/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:37:23 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/10/24 15:37:23 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_valid_fd(char *str)
{
	long int	fd;

	fd = ft_long_atol(str);
	if (fd > INT_MAX)
		return (false);
	return (true);
}
