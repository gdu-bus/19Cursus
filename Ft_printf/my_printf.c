/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:33:22 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/03/06 12:26:47 by gauthier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void my_printf_str(va_list *my_list)
{
    char  *src = va_arg(*my_list, char *);

    write(1, src, strlen(src));
}

void my_printf_char(va_list *my_list)
{
    char  c = va_arg(*my_list, int);

    write(1, &c, 1);
}

void my_printf_nbr(va_list *my_list)
{
    int num = va_arg(*my_list, int);

    char buffer[20];
    sprintf(buffer, "%d", num);
    write(1, buffer, strlen(buffer));
}

int findIndex(char *tab, char element)
{
    int index = 0;

    while (tab[index] != 0)
    {
        if (tab[index] == element)
            return (index);
	index++;
    }
    return (-1);
}

void my_printf(char *format, ...)
{
    void (*tabFunction[3]) (va_list *) = { my_printf_str, my_printf_char
                                                        , my_printf_nbr};
    char tabIndex[4] = {'s', 'c', 'd', 0};
    va_list my_list;
    int i = 0;
    int tmpIndex = 0;

    va_start(my_list, format);
    while (format[i] != 0)
    {
        if (i != 0 && format[i - 1] == '%')
        {
            tmpIndex = findIndex(tabIndex, format[i]);
            if (tmpIndex != -1)
                (*tabFunction[tmpIndex]) (&my_list);
        }
        else if (format[i] != '%')
            write(1, &format[i], 1);
	i++;
    }
}

int main(int ac, char const **argv)
{
	ac = 0;
	argv = NULL;
	my_printf("Ecriture avant les variables\n%s\n%d\n%c\n", "Ecriture apres les variables", 42, 'q');
}
