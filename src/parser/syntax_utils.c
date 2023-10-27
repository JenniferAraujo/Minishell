/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:16:33 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:15:41 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_token(t_type type)
{
	char	*token;

	if (type == IN)
		token = "<";
	if (type == OUT)
		token = ">";
	if (type == APPEND)
		token = ">>";
	if (type == HEREDOC)
		token = "<<";
	return (token);
}

bool	is_rdr(t_type type)
{
	if (type == OUT || type == IN
		|| type == HEREDOC || type == APPEND)
		return (true);
	return (false);
}

bool	is_emptyrdr(t_token token)
{
	if (is_rdr(token.type) && (token.arr == 0))
		return (true);
	return (false);
}
