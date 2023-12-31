/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:07 by joe               #+#    #+#             */
/*   Updated: 2023/10/27 00:19:28 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include "minishell.h"

/*
!QUOTES
*/
void	print_quotes(t_quotes *quotes);
int		check_quotes_print(t_main *main, t_variables_quotes *s_var_quotes);
int		update_erro_quotes(int quotes_analises, t_main *main);
void	verify_quotes(t_main *main, t_variables_quotes *s_var_quotes);

/*
!QUOTES_UTILS.C
*/
void	create_quotes_node(t_quotes *quotes, int open_q_t, int open_q_p, int i);
int		check_quotes(char c, int quotes);
char	*remove_empty_quotes(char *prompt);

/*
!QUOTES_SUBSTR
*/
void	quotes_substr(t_quotes *quotes, char *str);

/*
!QUOTES_LIST.C
*/
void	shift_index_quotes(t_quotes *stack);
void	insert_last_quotes(t_quotes *stack, t_node_quotes *new);

#endif
