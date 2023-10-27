/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:53 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/10/18 15:24:53 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//* Esta funcao vai verificar se nos comandos foi inserido um $ para poder
//*  prosseguir com a expansao
void	check_expansion_arr(t_main *main, char ***arr)
{
	int		i;

	i = 0;
	if (main->flags.hd)
		return ;
	while (arr[0][i])
	{
		if (ft_strchr(arr[0][i], '$'))
			arr[0][i] = expand(main, arr[0][i]);
		i++;
	}
	del_emptyline(*arr);
	if (**arr == NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}

//* Esta funcao vai verificar se existe um $ numa string
//*  para poder prosseguir com a expansao
char	*check_expansion_str(t_main *main, char *str)
{
	if (main->flags.hd)
		return (str);
	if (ft_strchr(str, '$'))
	{
		str = expand(main, str);
		if (*str == '\0')
		{
			printf("entra aqui\n");
			free(str);
			return (NULL);
		}
	}
	return (str);
}

//* Função de ajuda da del_emptyline que remove apenas
//*  uma única linha da array
void	del_emptyline_while(char **arr, int *j)
{
	ft_free_str(&arr[(*j)]);
	arr[(*j)] = ft_calloc(ft_strlen(arr[(*j) + 1]) + 1, sizeof(char *));
	ft_strlcpy(arr[(*j)], arr[(*j) + 1], ft_strlen(arr[(*j) + 1]) + 1);
	(*j)++;
}

//* Função para apagar todas as linhas vazias da
//*  array dos tokens
void	del_emptyline(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '\0')
		{
			if (arr[i + 1] == NULL)
			{
				printf("entra aqui 0\n");
				ft_free_str(&arr[i]);
			}
			else
			{
				j = i;
				while (arr[j + 1])
					del_emptyline_while(arr, &j);
				ft_free_str(&arr[j]);
				arr[j] = NULL;
			}
		}
		i++;
	}
}
