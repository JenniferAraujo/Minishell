/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:04:16 by jcruz-da          #+#    #+#             */
/*   Updated: 2023/10/23 16:04:16 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_ex_status;

//!-----------------------> CRTL + C <--------------------------
/**
 * Manipulador de sinal para o sinal SIGINT (interrupção do terminal).
 *
 * Esta função é chamada quando o processo recebe um sinal SIGINT, que é
 * geralmente enviado quando o usuário pressiona Ctrl+C no terminal. Ela
 * atualiza o status de saída para 130, limpa a linha atual, exibe uma nova linha
 * e redisplay o prompt.
 *
 * @param sig O número do sinal recebido, geralmente SIGINT.
 */
void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_ex_status = 130;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		g_ex_status = 130;
		ft_printf("\n");
	}
	else if (sig == SIGQUIT)
	{
		g_ex_status = 131;
		ft_printf("Quit (core dumped)\n");
	}
}

void	signal_handler_hd(int sig)
{
	t_main	*main;

	if (sig == SIGINT)
	{
		ft_printf("\n");
		main = get_main(NULL);
		ft_exit(NULL, true, main, true);
	}
}

void	signal_handler_nothing(int sig)
{
	if (sig == SIGINT)
		g_ex_status = 130;
}

void	signals(int options)
{
	if (options != 1)
		signal(SIGQUIT, SIG_IGN);
	if (options == 0)
		signal(SIGINT, signal_handler);
	else if (options == 1)
	{
		signal(SIGINT, signal_handler_child);
		signal(SIGQUIT, signal_handler_child);
	}
	else if (options == 2)
		signal(SIGINT, signal_handler_hd);
	else if (options == -1)
		signal(SIGINT, signal_handler_nothing);
}
