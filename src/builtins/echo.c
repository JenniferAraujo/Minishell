/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:04:44 by jede-ara          #+#    #+#             */
/*   Updated: 2023/09/29 11:48:01 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int echo_newline(char *command)
{
    int count;

    if (ft_strncmp(command, "-n", 2))
		return (0);
    count = 2;
    while (command[count])
    {
        if (command[count] != 'n')
			return (0);
        count++;
    }
	return (1);
}
void    echo(char **command, t_main *main, bool child)
{
    int flag;
    int count;
	if (command[1] == NULL)
		ft_printf("\n");
	else
	{

		flag = 0;
		count = 1;
		while (command[count] && echo_newline(command[count]))
		{
			flag = 1;
			count++;
		}
		count = 1;
		if (flag)
		{
			ft_printf("\n");
			count = 2;
			while (command[count])
			{
				if(ft_strcmp(command[count], "-n"))
				{
					ft_printf("%s", command[count]);
					if (command[count + 1])
						ft_printf(" ");
				}
				count++;
			}
		}
		while (command[count])
		{
			if (!flag)
			{
				ft_printf("%s", command[count]);
				if (command[count + 1])
					ft_printf(" ");
			}
			count++;
		}
		if (!flag)
			ft_printf("\n");
		if (child)
			exit(0);
		set_exit_code(main, 0);
	}
}