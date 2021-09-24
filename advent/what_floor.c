/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include <unistd.h>
#include <stdio.h>

int     main()
{
   int  count;
   int  pos;
   int  i;
   char c;

   count = 0;
   pos = 0;
   i = 0;
   while (read(STDIN_FILENO, &c, 1))
   {
       if (count == -1 && pos == 0)
       {
           pos = i;
       }
       if (c == '(')    count++;
       if (c == ')')    count--;
       i++;
   }
   
   printf("star 1 : %i\nstar 2 : %i\n", count, pos);
}
