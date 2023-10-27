/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jede-ara <jede-ara>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:14:27 by jede-ara          #+#    #+#             */
/*   Updated: 2023/08/31 00:14:27 by jede-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	read_stdin_aux(char *str, char *lim, t_main *main, int *line)
{
	if (!str)
	{
		error_msg_hd(lim, main->fd.stdout, main->line);
		return (-1);
	}
	(*line)++;
	if (!*str && !lim)
		return (-1);
	if (!lim)
		return (0);
	if (!ft_strncmp(lim, str, get_max(ft_strlen(lim), ft_strclen(str, '\n'))))
	{
		ft_free_str(&str);
		return (-1);
	}
	return (0);
}

int	read_stdin(int fd, char *lim, bool quotes, t_main *main)
{
	int		line;
	char	*str;

	line = 0;
	while (1)
	{
		str = readline("> ");
		if (read_stdin_aux(str, lim, main, &line) == -1)
			break ;
		if (!quotes)
			str = check_expansion_str(main, str);
		if (str)
			write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		if (str)
			ft_free_str(&str);
	}
	return (line);
}

int	open_hd(char *lim, bool quotes, t_main *main)
{
	int		heredoc_fd[2];
	int		pid;
	int		hd_line;

	error_fp(pipe(heredoc_fd), errno, main);
	signals(2);
	pid = fork();
	error_fp(pid, errno, main);
	get_main(main);
	if (pid == 0)
	{
		close(heredoc_fd[0]);
		hd_line = read_stdin(heredoc_fd[1], lim, quotes, main);
		close(heredoc_fd[1]);
		exit_child(main, hd_line, true);
	}
	signals(-1);
	close(heredoc_fd[1]);
	wait_set_line(pid, main);
	return (heredoc_fd[0]);
}

void	rdr_hd(t_main *main, int fd, int rdr_fd)
{
	if (rdr_fd == -666)
		dup2(fd, STDIN_FILENO);
	else
	{
		if (dup2(fd, rdr_fd) == -1)
			rdr_error(ft_itoa(rdr_fd), main, 1);
	}
	close(fd);
}
