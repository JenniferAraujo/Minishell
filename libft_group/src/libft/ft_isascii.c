/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:04:11 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/11/07 16:12:21 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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

	c = '^';
	printf("By my function:\n");
	printf("%d\n", ft_isascii(c));
	printf("By the original:\n");
	printf("%d\n", isascii(c));
}
*/
