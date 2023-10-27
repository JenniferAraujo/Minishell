/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:46:08 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:08 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_input(t_main *main)
{
	ft_free_str(&main->input);
	free_quotes(&main->quotes);
	free_lexer(&main->tokens);
	free_ast(&main->ast);
	ft_free_array(&main->env_arr);
}

void	destroy_main(t_main *main, bool input)
{
	if (input)
		destroy_input(main);
	free_env(&main->env_list);
	free_env(&main->export_list);
}
