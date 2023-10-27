/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:17:24 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:18:10 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*Essa funcao usa o getcmd para retornar o path atual*/
void	pwd(t_main *main, bool child)
{
	char	*pwd;

	pwd = ft_calloc(sizeof(char), 4096);
	getcwd(pwd, 4096);
	ft_printf("%s\n", pwd);
	free(pwd);
	exit_child(main, 0, child);
}
