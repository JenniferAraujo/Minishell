/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:00:31 by joe               #+#    #+#             */
/*   Updated: 2023/08/19 17:16:53 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
COLORS
*/
# define RESET "\033[0m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN 	"\033[1;36m"
# define WHITE 	"\033[1;37m"
# define BRIGHT_BLUE "\033[1;94m"
# define BRIGHT_MAGENTA 	"\033[1;95m"
# define GRAY	"\033[1;90m"
# define COL_RESET     "\x1b[0m"
# define BCKGRD_COL_RED   "\e[48;2;200;0;0m"
# define BCKGRD_COL_GREEN "\e[48;2;0;200;0m"
# define BCKGRD_COL_BLUE  "\e[48;2;0;0;200m" // where rrr;ggg;bbb in 48;2;rrr;ggg;bbbm can go from 0 to 255 respectively
# define BCKGRD_COL_MIKU   "\e[48;2;71;200;192m"
# define BCKGRD_COL_PINK "\e[48;2;255;204;229m"
# define BCKGRD_COL_WHITE "\e[48;2;255;255;255m"
# define COLOR_BOLD  "\x1B[1m"
# define COLOR_OFF   "\x1B[0m"
# define ANSI_COLOR(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
# define RGB_MIKU_ARROW ANSI_COLOR(255, 98, 157)
# define RGB_MIKU ANSI_COLOR(135, 229, 207)
# define RGB_MIKU_PINK ANSI_COLOR(225, 22, 136)
# define RGB_MAGENTA ANSI_COLOR(156, 17, 156)
# define RGB_CYAN ANSI_COLOR(0, 139, 139)
# define RGB_BLUE ANSI_COLOR(45, 55, 140)
# define RGB_GREEN ANSI_COLOR(34, 151, 86)
# define RGB_PINK ANSI_COLOR(209, 116, 168)

# define SYNTAX_ERROR "syntax error near unexpected token `"
# define CMD_ERROR "command not found"
# define FILE_ERROR "No such file or directory"

#endif
