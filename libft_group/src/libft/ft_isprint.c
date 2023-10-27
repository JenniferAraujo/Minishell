/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:38:27 by jcruz-da          #+#    #+#             */
/*   Updated: 2022/11/08 14:53:51 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	c = '\n';
	printf("By my function:\n");
	printf("%d\n", ft_isprint(c));
	printf("By the original:\n");
	printf("%d\n", isprint(c));
}
*/
