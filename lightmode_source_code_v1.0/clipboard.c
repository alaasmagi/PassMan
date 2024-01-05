/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clipboard.h"

int CopyToClipboard(char *string) 
{
    FILE *pipe = popen("xclip -selection clipboard", "w");
    if (pipe == NULL) 
    {
        printf("Cannot open pipe\n");
        exit(EXIT_FAILURE);
    }
   
    fprintf(pipe, "%s", string);
    pclose(pipe);
    
    return EXIT_SUCCESS;
}
