/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:58:11 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/11/07 16:03:19 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
	{
		return (1);
	}
	else
		return (0);
}
/*
int	main(void)
{
	int	c;

	c = '=';
	printf("By my function:\n");
	printf("%d\n", ft_isalnum(c));
	printf("By the original:\n");
	printf("%d\n", isalnum(c));
}
*/
