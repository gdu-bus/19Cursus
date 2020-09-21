/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <gdu-bus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:05:18 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/09/21 11:17:42 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>
 // #include <stdarg.h>
 // #include <unistd.h>
//
// /*Ò
// ** FCT ajoutée
// */
// size_t  ft_strlen(char *str)
// {
//   size_t  len;
//
//   if (!str)
//     return (0);
//   len = 0;
//   while (str[len])
//     len++;
//   return (len);
// }
// /*
// ** %s
// */
// void   my_printf_str(va_list *my_list)
// {
//   char *src = va_arg(*my_list, char *);
//
//   write(1, src, ft_strlen(src));
// }
// /*
// ** %c
// */
// void my_printf_char(va_list *my_list)
// {
//     char c = va_arg(*my_list, int);
//
//     write(1, &c, 1);
// }
// /*
// ** %d
// */
// void my_printf_nbr(va_list *my_list)
// {
//   //faire un putnbr pour remplacer sprintf
//     int num = va_arg(*my_list, int);
//
//     char buffer[20];
//     sprintf(buffer,"%d", num);
//     write(1, buffer, ft_strlen(buffer));
// }
// /*
// ** sert à trouver l'index du tableau
// */
// int    findIndex(char *tab, char element)
// {
//   int index;
//
//   index = 0;
//   while (tab[index] != 0)
//   {
//     if (tab[index] == element)
//       return index;
//     index++;
//   }
//   return (-1);
// }
//
// void   my_printf(char *src, ...)
// {
//   // ceci est un tableau de poiteurs sur fonctions qui ont toutes le même type
//   // de retour -> void
//   void (*tabFunction[3]) (va_list *) = {my_printf_str, my_printf_char,
//                                         my_printf_nbr};
//   char tabIndex[4] = {'s', 'c', 'd', 0};
//   va_list my_list;
//   int tmpIndex = 0;
//   int i = 0;
//   va_start(my_list, src);
//   while (src[i])
//   {
//     if (i != 0 && src[i - 1] == '%')
//     {
//       tmpIndex = findIndex(tabIndex, src[i]);
//       if (tmpIndex != -1)
//         (*tabFunction[tmpIndex]) (&my_list);
//     }
//     else if (src[i] != '%')
//       write(1, &src[i], 1);
//     i++;
//   }
//
//
// }

int    main(void)
{
  ft_printf("AZERTY %c\n", 'q');
  return (0);
}
