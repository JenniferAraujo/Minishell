/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>                +#+  +:+       +#+  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:35:09 by rimarque          #+#    #+#             */
/*   Updated: 2023/10/18 15:51:07 by jcruz-da            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_out(t_node	*head, t_main *main)
{
	t_node	*aux;

	aux = head;
	while (aux != NULL)
	{
		exec_rdr(aux->token, main, 0);
		aux = aux->next;
	}
}
