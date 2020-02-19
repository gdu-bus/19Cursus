/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:49:00 by gdu-bus-          #+#    #+#             */
/*   Updated: 2020/02/19 14:49:03 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   adjust_content(int fd, char **line, char **rest)
{
  int   check;

  check = ft_strchr(*line, '\n');
  free(rest[fd]);
  if (check != -1)
  {
    if (!(rest[fd] = ft_strdup(*line + check + 1)))
      return (-1);
    if (!(*line = ft_substr(*line, 0, check)))
      return (-1);
  }
  else
  {
    rest[fd] = NULL;
    return (0);
  }
  return (1);
}

int   read_line(int fd, char **line, char **rest)
{
  int   ret;
  int   check;
  char  *buf;

  if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char)))) // création de buffer qui contiendra la ligne lue.
    return (-1);
  if (!(*line = ft_strdup(rest[fd]))) // copie le contenu du rest (la lecture précédente) dans line.
    return (-1);
  while ((ret = read(fd, buf, BUFFER_SIZE)) > 0) // lecture tant que EOF n'est pas atteint et pas d'erreur.
  {
    buf[ret] = '\0'; // rajout d'un \0 pour cloturer la string
    if (!(*line = ft_strjoin(*line, buf))) // assemblage du contenu de line et buf.
      return (-1);
    check = ft_strchr(*line, '\n');
    if (check != -1) // arrêt de lecture si \n dans la ligne
      break;
  }
  free(buf);
  if (ret < 0)
    return (-1); // en cas d'erreur de fichier
  return (adjust_content(fd, line, rest)); // ajustement du contenu de line pour n'avoir plus que la string dans line et le reste dans rest.
}

int   get_next_line(int fd, char **line)
{
  static char   *rest[OPEN_MAX];

  if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE < 1) // vérifier que toutes les condtions soient respectés pour
    return (-1);                                           // commencer le programme.
  if (!rest[fd])
    if (!(rest[fd] = ft_strdup(""))) // création de ce qui contiendra le reste.
      return (-1);
  return (read_line(fd, line, rest)); // read_line étant la fonction qui lit et récupère une ligne.
}
