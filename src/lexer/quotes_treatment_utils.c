/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:18:42 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/10/18 16:18:42 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**str_to_arr(char *str, bool free)
{
	char	**result;

	result = ft_calloc(2, sizeof(char *));
	result[0] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	ft_strlcpy(result[0], str, ft_strlen(str) + 1);
	if (free)
		ft_free_str(&str);
	return (result);
}
