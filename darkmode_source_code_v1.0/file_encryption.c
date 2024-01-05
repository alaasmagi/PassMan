/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_db.h"

int FileEncrypt(int user_id, char *filename)
{
    char en_key[MAX_LEN];
    snprintf(en_key, sizeof(en_key), "%d", user_id + 314);
    
    char line[MAX_LEN * 2];                                 
    sprintf(line, "ccrypt -k - %s", filename);

    FILE *f = popen(line, "w"); 
    
    fprintf(f, "%s\n", en_key);
    
    pclose(f);
    
    return EXIT_SUCCESS;
}

