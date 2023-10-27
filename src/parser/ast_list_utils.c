/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:45:44 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:15:41 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*node_dup(t_node *src)
{
	t_node	*dst;

	dst = malloc(sizeof(t_node));
	if (!dst)
		return (NULL);
	dst->token = src->token;
	return (dst);
}

void	init_list_ast(t_lexer *list)
{
	list->head = NULL;
	list->size = 0;
	list->str_len = 0;
}
