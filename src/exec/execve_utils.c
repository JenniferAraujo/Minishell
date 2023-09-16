/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:46:02 by rimarque          #+#    #+#             */
/*   Updated: 2023/09/15 14:06:57 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_pathname(char	*pathname, int flag)
{
	if (flag == 1)
		ft_free_str(&pathname);
}

void	error_management(char *str)
{
	if (ft_strncmp("/", str, 1) && ft_strncmp("./", str, 2)) //cmd normal
		error_msg_cmd(str, STDERR_FILENO);
	else 													//se começar por "/"" (ou seja se der o caminho)
		error_msg_file(str, STDERR_FILENO);
	exit(127);
}
