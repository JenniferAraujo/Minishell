/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:05:20 by dinoguei          #+#    #+#             */
/*   Updated: 2023/10/28 14:14:32 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen((char *)str);
	ptr = malloc((len + 1) * sizeof(const char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = *str;
		i++;
		str++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_arrdup_bzero_last(char **arr, char c)
{
	int		i;
	int		len;
	char	**ptr;

	len = ft_arrlen((char **)arr);
	ptr = malloc((len + 2) * sizeof(const char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = ft_strdup(arr[i]);
		i++;
	}
	if(c == '\t' || c == ' ')
	{
		ptr[i] = ft_strdup("\0");
		ptr[i + 1] = NULL;
	}
	else
		ptr[i] = NULL;
	ft_free_array(&arr);
	return (ptr);
}

char	**ft_arrdup_bzero_first(char **arr, char c)
{
	int		i;
	int		j;
	int		len;
	char	**ptr;

	j = 0;
	len = ft_arrlen((char **)arr);
	ptr = malloc((len + 2) * sizeof(const char *));
	if (!ptr)
		return (NULL);
	if(c == '\t' || c == ' ')
	{
		ptr[0] = ft_strdup("\0");
		i = 1;
	}
	else
		i = 0;
	while (j < len)
	{
		ptr[i] = ft_strdup(arr[j]);
		i++;
	}
	ptr[i] = NULL;
	ft_free_array(&arr);
	return (ptr);
}

char	**ft_arrdup(char **arr)
{
	int		i;
	int		len;
	char	**ptr;

	len = ft_arrlen((char **)arr);
	ptr = malloc((len + 1) * sizeof(const char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = ft_strdup(arr[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

/*int	main(void)
{
	char	**teste;
	char	**testecpy;

	teste = ft_calloc(sizeof(char *), 4);
	teste[0] = ft_calloc(sizeof(char), 4);
	teste[0] = "ola";
	teste[1] = ft_calloc(sizeof(char), 5);
	teste[1] = "tudo";
	teste[2] = ft_calloc(sizeof(char), 4);
	teste[2] = "bem";
	teste[3] = NULL;

	printf("Original:\n");
	print_arr(teste);
	printf("Cpy:\n");
	testecpy = ft_arrdup(teste);
	print_arr(testecpy);
}*/
