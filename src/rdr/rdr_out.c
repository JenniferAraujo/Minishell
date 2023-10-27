/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:56:07 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/30 19:56:07 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rdr_out(char **arr, t_main *main, int rdr_fd)
{
	int	fd;

	if (check_errors(main, arr))
		return ;
	fd = open(arr[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		rdr_error(arr[0], main, 0);
	else if (rdr_fd == -666)
		dup2(fd, STDOUT_FILENO);
	else
	{
		if (dup2(fd, rdr_fd) == -1)
			rdr_error(ft_itoa(rdr_fd), main, 1);
	}
	close(fd);
}
