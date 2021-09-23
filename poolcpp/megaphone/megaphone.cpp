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

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int     i;
    int     j;

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (std::islower(argv[i][j]))
                std::cout << (char) std::toupper(argv[i][j]);
            else
                std::cout << argv[i][j];
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}

/*

#include <iostream>

int main(int argc, char **argv)
{
    int     i;
    int     j;

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] <= 'z' && argv[i][j] >= 'a')
                argv[i][j] -= ' ';
            j++;
        }
        std::cout << argv[i];
        i++;
    }
    std::cout << std::endl;

    return (0);
}

*/
