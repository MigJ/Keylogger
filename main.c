/*
** main.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Mon Dec 19 16:49:34 2016 Nathan Trehout
** Last update Mon Dec 19 17:31:46 2016 Nathan Trehout
*/

#include "include/my.h"
#include "include/struct.h"

int	is_prefix(char *p)
{
  if (p[0] == 's' && p[1] == 'u' && p[2] == 'd' && p[3] == 'o')
    return (1);
  else if (p[0] == 'f' && p[1] == 'i' && p[2] == 'r' && p[3] == 'e' && p[4] == 'f' && p[5] == 'o' && p[6] == 'x')
    return (2);
  else
    return (84);
}

int	write_in_file(char *path, char *to_write, char *prefix)
{
  
  
  return (0);
}


int	main()
{
  is_prefix("sudo");
  return (0);
}
