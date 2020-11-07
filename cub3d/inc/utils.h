/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:24:35 by lorenuar          #+#    #+#             */
/*   Updated: 2020/10/23 15:51:50 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** ANSI Colors
*/
# define RST "\033[0m"
# define RED "\033[31m"
# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYA "\033[36m"
# define WHI "\033[37m"

/*
** ANSI Colors Presets
*/
# define ERR "\033[91;1m"

/*
** Alloc_and_Free
*/
void	free_and_null(void **ptr);

/*
** Error
*/
int		free_on_error(int ret, void **ptr, char *s);
int		put_error(int ret, char *s);

/*
** Numbers
*/
size_t	parse_num(const char *s);

/*
** Strings
*/
int		is_charset(char c, char *set);
size_t	str_len(const char *s);
int		str_ncmp(const char *s1, const char *s2, size_t size);

/*
** Strings/Printing
*/
int		put_chr_fd(int fd, char c);
int		put_str_fd(int fd, char *s);

/*
** Strings/get_next_line
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

int		get_next_line(int fd, char **line);
char	*jointo(char *s1, char *s2, char **tofree);
size_t	hasto(char *s, char c);

#endif
