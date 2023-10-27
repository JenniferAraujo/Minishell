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

void	error_msg_cmd(char	*str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(CMD_ERROR, fd);
}

void	error_msg_file(char *file, int fd, char *msg)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(file, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(msg, fd);
}

void	error_msg_fd(char *str, int fd)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": ", fd);
	ft_putendl_fd(FD_ERROR, fd);
}

void	error_msg_hd(char *str, int fd, int line)
{
	ft_putstr_fd("minishell: warning: ", fd);
	ft_putstr_fd("here-document at line ", fd);
	ft_putnbr_fd(line, fd);
	ft_putstr_fd(" delimited by end-of-file", fd);
	ft_putstr_fd(" (wanted `", fd);
	ft_putstr_fd(str, fd);
	ft_putendl_fd("')", fd);
}

void	error_cd(int fd, char *str)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd("cd: ", fd);
	ft_putstr_fd(str, fd);
	ft_putendl_fd(" not set", fd);
}
