/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:45:44 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/08/22 15:45:44 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Funcao de ajuda para a get_rdr_out que verifica
bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

//* Aqui vai identificar para onde se vai mandar o output do caracter
void	get_rdr_out(t_main *main, int *i, t_type token)
{
	int		start;
	char	*str;
	bool	run;

	run = true;
	while (is_space(main->input[*i]) == true)
		(*i)++;
	start = *i;
	while (*i <= main->tokens.str_len && run && main->input[*i])
	{
		if (special_chr(main->input[*i]) == true
			&& check_index_quotes(main, i) == false)
			break ;
		if (is_space(main->input[*i]) == false)
			(*i)++;
		else if (check_index_quotes(main, i) == false)
			run = false;
		else
			(*i)++;
	}
	str = ft_substr(main->input, start, (*i - start));
	add_token(main, token, str, NULL);
	(*i)--;
	free(str);
}

t_type	get_type(t_main *main, int *i, int index)
{
	if (index == (int)OUT)
	{
		if (*i + 1 <= main->tokens.str_len
			&& main->input[*i + 1] == (char)index)
			return (APPEND);
		else
			return (OUT);
	}
	else
	{
		if (*i + 1 <= main->tokens.str_len
			&& main->input[*i + 1] == (char)index)
			return (HEREDOC);
		else
			return (IN);
	}
	return (EMPTY);
}

//* Esta funcao identifica os caracteres de output, quer append quer redirect
void	search_output_tokens(t_main *main, int *i)
{
	t_type	type;

	type = get_type(main, i, OUT);
	if (type == APPEND)
		(*i) += 2;
	else
		(*i)++;
	get_rdr_out(main, i, type);
}
