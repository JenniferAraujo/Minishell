/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:14:27 by rimarque          #+#    #+#             */
/*   Updated: 2023/08/31 00:14:27 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*read_stdin(char *lim, bool quotes, t_main main)
{
	char	*str;
	char	*buff;

	str = "\0";
	buff = "\0";

	while (1)
	{
		//printf("entra aqui??\n");
		write(main.fd.stdout, "> ", 2);
		//printf("entra aqui?? 2\n");
		str = get_next_line(STDIN_FILENO, false);
		if(!str)
		{
			write(main.fd.stdout, "\n", 1);
			exit(0);
		}
		printf("entra aqui?? 3\n");
		if(!quotes)
		{
			//!str = expand_line(str, quotes);
		}
		printf("entra aqui?? 4\n");
		if (!ft_strncmp(lim, str, get_max(ft_strlen(lim), ft_strclen(str, '\n'))))
		{
			printf("entra aqui\n");
			ft_free_str(&str);
			break ;
		}
		buff = ft_strjoinfree(buff, str);
		ft_free_str(&str);
	}
	printf("entra aqui??\n");
	return (buff);
}

int	open_hd(char *lim, bool quotes, t_main *main)
{
	int		heredoc_fd[2];
	char	*buff;
	int pid;
	int exit_status;

	if (pipe(heredoc_fd) == -1)
	{
		//!error_management(NULL, 0, errno); //*errno -> number of last error
	}
	signals(false, true, false);
	pid = fork();
	if (pid == 0)
	{
		close(heredoc_fd[0]);
		buff = read_stdin(lim, quotes, *main);
		write(heredoc_fd[1], buff, strlen(buff));
		close(heredoc_fd[1]);
		if (*buff)
			ft_free_str(&buff);
		exit(0);
	}
	close(heredoc_fd[1]);
	signals(false, false, true);
	waitpid(pid, &exit_status, 0);
	if (WEXITSTATUS(exit_status) != 0)
		{
			set_exit_code(main, WEXITSTATUS(exit_status));
		}
	else
		set_exit_code(main, 0);
	return(heredoc_fd[0]);
}

void	rdr_hd(t_token token, t_main *main, int fd)
{
	if(token.arr[1] == NULL)
	{
		//fd = open_hd(token.arr[0], token.quotes, main);
		dup2(fd, STDIN_FILENO);
	}
	else
	{
		//fd = open_hd(token.arr[1], token.quotes, main);
		if(dup2(fd, ft_atoi(token.arr[0])) == -1)
		{
			//!std_err
		}
	}
	close(fd);
}

