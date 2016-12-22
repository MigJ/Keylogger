/*
** main.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger
**
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Dec 19 16:49:34 2016 Nathan Trehout
** Last update Tue Dec 20 21:14:40 2016 Nathan Trehout
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>



int	main()
{
  init("salut tout le monde !", "sudo");
  return (0);
}
