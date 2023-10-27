/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:47:14 by jede-ara          #+#    #+#             */
/*   Updated: 2023/10/27 20:15:41 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "minishell.h"

/*
!ENVP
*/
t_var		*var_node(char *var);
void		add_var(t_env *env, t_var *var_new, int index);
void		shift_index_env(t_env *stack);
void		set_env_list(t_main *main, char **envp);
void		print_var(t_env env);
void		set_env_arr(t_main *main);

#endif
