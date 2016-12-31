/*
** tools.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/src
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Sat Dec 31 15:07:47 2016 Nathan Trehout
** Last update Sat Dec 31 15:07:48 2016 Nathan Trehout
*/

#include "my.h"

int     strlencharchar(char **dest)
{
  int   i;

  i = 0;
  while (dest[i] != 0)
    i++;

  return (i);
}
