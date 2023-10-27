/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:46:29 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:15:41 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_errors(t_main *main, char **arr)
{
	if (main->flags.rdr_err)
		return (true);
	if (!*arr)
	{
		rdr_error("\0", main, 0);
		return (true);
	}
	if (arr[0][0] == '$')
	{
		rdr_error(arr[0], main, 2);
		return (true);
	}
	return (false);
}
