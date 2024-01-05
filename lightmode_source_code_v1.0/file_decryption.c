/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main_db.h"

int FileDecrypt(int user_id, char *filename)
{
    char de_key[MAX_LEN];
    snprintf(de_key, sizeof(de_key), "%d", user_id + 314);
    
    char line[MAX_LEN * 2];                                 
    sprintf(line, "ccrypt -d -k - %s", filename);

    FILE *f = popen(line, "w"); 
    
    fprintf(f, "%s\n", de_key);
    
    pclose(f);
    
    return EXIT_SUCCESS;
}
