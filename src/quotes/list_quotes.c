/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:44:59 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:15:41 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/structs.h"

void	shift_index_quotes(t_quotes *stack)
{
	t_node_quotes	*element;

	stack->head->index = 0;
	element = stack->head->next;
	while (element != stack->head)
	{
		element->index = element->prev->index + 1;
		element = element->next;
	}
}

void	put_head_node_quotes(t_quotes *stack, t_node_quotes *new)
{
	stack->head = new;
	new->next = stack->head;
	new->prev = stack->head;
}

void	insert_last_quotes(t_quotes *stack, t_node_quotes *new)
{
	if (stack->head == NULL)
		put_head_node_quotes(stack, new);
	else
	{
		stack->head->prev->next = new;
		new->prev = stack->head->prev;
		new->next = stack->head;
		stack->head->prev = new;
	}
	stack->size++;
}
