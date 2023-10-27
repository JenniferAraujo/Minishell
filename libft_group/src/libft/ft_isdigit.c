/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:49 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/11/21 13:48:22 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	c;

	c = 'a';
	printf("By my function:\n");
	printf("%d\n", ft_isdigit(c));
	printf("By the original:\n");
	printf("%d\n", isdigit(c));
}
*/
