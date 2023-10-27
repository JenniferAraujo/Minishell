/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:46:15 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/19 00:46:15 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/structs.h"

void	error_export(int fd)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putendl_fd("bad assignment", fd);
}

void	error_with_arg(int fd, char *str)
{
	ft_putstr_fd("env: ", fd);
	ft_putstr_fd(str, fd);
	ft_putendl_fd(": No such file or directory", fd);
}

void	error_syntax(char *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(SYNTAX_ERROR, STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
