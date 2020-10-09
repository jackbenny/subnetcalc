/* A very simple subnet calculator in C, written by
 * Jack-Benny Persson (jack-benny@cyberinfo.se).
 * Released under GNU GPLv2.
 * Version 1.0 (2020-10-09)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkInput(char input[]);
long int calcAddr(int netmask);
long int calcHosts(int netmask);
void printAddr(int netmask);
void printHelp(char progname[]);

int main(int argc, char *argv[])
{
    char input[4] = { 0 };
    int net;

    if (argc == 1) /* User didn't supply an argument, go interactive */
    {
        printf("Enter netmask in slash-notation without the slash: ");
        scanf("%2c", input);

        if (checkInput(input))
        {
            net = atoi(input);
            printAddr(net);
            return 0;
        }
        else  /* If the user entered anything else than 0-32 */
        {
            printHelp(argv[0]);
            return 1;
        }
    }
    else if (argc == 2) /* User supplied exactly one argument */
    {
        if ( strcmp("-s", argv[1]) == 0) /* User wants a silent batch */
        {
            while(fgets(input, sizeof(input), stdin) != NULL)
            {
                /* Check if netmask is numeric (and do conversion) */
                if( checkInput(input) )
                {
                    printf("%ld\n", calcAddr(atoi(input)));
                }
                else
                {
                    printHelp(argv[0]);
                    return 1;
                }
            }
        }
        else if (checkInput(argv[1]))
        {
            net = atoi(argv[1]);
            printAddr(net);
        }
        else
        {
            printHelp(argv[0]);
            return 1;
        }
    }
    else /* User supplied to many arguments */
    {
        printHelp(argv[0]);
        return 1;
    }
    return 0;
}

int checkInput(char input[])
{
    int netmask;
    /* Sanity check the user input */
    if( strspn(input, "0123456789\n") == strlen(input) )
    {
        netmask = atoi(input);
        if (netmask >= 0 && netmask <= 32)
        {
            return 1;
        }
        else
        {
            printf("Only values between 0 and 32 are accepted\n\n");
            return 0;
        }
    }
    else
    {
        printf("Only values between 0 and 32 are accepted\n\n");
        return 0;
    }
}

long int calcAddr(int netmask)
{
    return pow(2, 32-netmask);
}

long int calcHosts(int netmask)
{
    long int hosts;
    hosts = (pow(2, 32-netmask))-2;
    if (hosts < 0) /* If usables hosts < 0, set to 0 */
    {
        hosts = 0;
    }
    return hosts;
}

void printAddr(int netmask)
{
    printf("Netmask bit: %d\n\n", netmask);	
    printf("%ld total addresses\n", calcAddr(netmask));
    printf("%ld usable addresses for hosts\n", calcHosts(netmask));
}

void printHelp(char progname[])
{
    printf("Usage: %s [netmask] [-s]\n", progname);
    printf("If the program is started without any arguments, "
            "it is started in interactive mode.\n"
            "Optionally, a netmask can be supplied as a "
            "argument.\n"
            "If the program is started with the -s option, "
            "the program will silently accept input on stdin,\n"
            "outputting the number of total address on stdout\n");
    printf("\nExample: %s \n"
           "Example: %s 24\n"
           "Example: %s -s\n", progname, progname, progname);
}

