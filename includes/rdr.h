/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:08:17 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:19:29 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RDR_H
# define RDR_H

# include "minishell.h"

/*
!INIT_RDR
*/
void	init_rdr(t_lexer tokens, t_main *main);
void	exec_rdr(t_token token, t_main *main, int hd);

/*
!RDR_APP
*/
void	rdr_app(char **arr, t_main *main, int rdr_fd);

/*
!RDR_HD
*/
int		open_hd(char *lim, bool quotes, t_main *main);
void	rdr_hd(t_main *main, int fd, int rdr_fd);

/*
!RDR_IN
*/
void	rdr_in(char **arr, t_main *main, int rdr_fd);

/*
!RDR_OUT
*/
void	rdr_out(char **arr, t_main *main, int rdr_fd);

/*
!RDR_UTILS
*/
void	exec_rdr(t_token token, t_main *main, int hd);
void	rdr_error(char *str, t_main *main, int options);
bool	ft_isexit(t_lexer tokens);
bool	check_cmd(t_lexer tokens);
void	find_exec_cmd_parent(t_lexer tokens, t_main *main);

bool	check_errors(t_main *main, char **arr);

#endif
