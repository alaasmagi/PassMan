/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_save.h"

int FileSave(main_users *database, int i)
{
    FILE *fp = fopen(MAIN_USERS, "a");
    if (fp == NULL)
    {
        perror("Tõrge! Faili avamisel tekkis viga!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d %s %s\n", database[i].user_id, 
    database[i].username, database[i].password);
    
    fclose(fp);
    return(EXIT_SUCCESS);
}


