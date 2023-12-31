/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:51:54 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 15:51:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//*A partir da posição seguinte ao 1o $ verifica se há mais $
bool	check_more_var(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

//* Função para descobrir o tamanho de um número
int	get_number_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != '\0')
	{
		len++;
		n = n / 10;
	}
	return (len);
}

//* Função de ajuda da expand que trata da expansão
//*  do exit code
char	*expand_exitcode(t_main *main, char *str)
{
	char	*expanded;
	char	*out;

	expanded = ft_itoa(main->exit_code);
	out = join_expanded(str, expanded, 2);
	free(expanded);
	return (out);
}

//* Função que transforma uma array numa string
char	*ft_arr_to_str(char **arr, char *str)
{
	int		i;
	char	*out;

	if (str[ft_strlen(str) - 1] == '$')
		out = ft_calloc(ft_arrlen(arr) + 1, sizeof(char *));
	else
		out = ft_calloc(ft_arrlen(arr) + 1, sizeof(char *));
	i = 0;
	while (arr[i])
	{
		out = ft_strjoinfree(out, arr[i]);
		i++;
	}
	if (str[ft_strlen(str) - 1] == '$')
		out[ft_strlen(out)] = '$';
	return (out);
}
