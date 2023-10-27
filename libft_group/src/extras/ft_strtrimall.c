/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:38:53 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/08/10 21:38:53 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

char	*ft_strtrimall(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (str[i] && ft_isspace(str[i]))
		i++;
	j = ft_strlen((char *)str);
	while (str[i] && ft_isspace(str[j + i]))
		j -= 1;
	return (ft_substr(str, 0, j + 1));
}
