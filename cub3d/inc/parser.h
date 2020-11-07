/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:24:35 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 15:49:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>
# include "cub3d.h"

/*
** Struct FileStats : storing useful information about a file
** - fd : file descriptor
** - total_lines : total number of lines read
** - max_lin_len : maximum length of all lines read
** - opt_lin_num : number of lines starting with an Identifier
** - map_lin_num : nunber of lines after opt_line_num
** - map_max_len : maximum length of all map lines
*/
typedef struct	s_filestats
{
	int			fd;
	size_t		total_lines;
	size_t		max_lin_len;
	size_t		opt_lin_len;
	size_t		map_lin_num;
	size_t		map_max_len;
}				t_fstat;

/*
** Error Codes
*/
# define ERROR 1
# define BAD_PATH "Invalid file path"

/*
** Parser
*/
int				parser(char *path);
int				check_path(char *path);

#endif
