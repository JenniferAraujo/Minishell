/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:16:33 by rimarque          #+#    #+#             */
/*   Updated: 2023/10/26 18:09:48 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (is_rdr(token.type)
		&& (token.arr == 0 || *token.arr == 0))
		return (true);
	return (false);
}
