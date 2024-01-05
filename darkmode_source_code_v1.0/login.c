/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

int LoginCompTest(char *i_user, char *i_pass)
{
    i_pass = PassHash(i_pass);
    main_users *data = NULL;
    FILE *fp;

    fp = fopen(MAIN_USERS, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Tõrge faili avamisel!\n");
        return EXIT_FAILURE;
    }

    data = malloc(sizeof(main_users));
    if (data == NULL)
    {       
        fprintf(stderr, "Tõrge mälu andmisel!\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    int i = 0;
    while (fscanf(fp, "%d %s %s",
                  &data[i].user_id, data[i].username, data[i].password) != EOF)
    {
        i++;
        data = realloc(data, (i + 1)*sizeof(main_users));
        if (data == NULL) 
        {
            fprintf(stderr, "Tõrge mälu andmisel!\n");
            fclose(fp);
            return EXIT_FAILURE;
        }
    }

    fclose(fp);
    int j;
    int user_id = 0;
    for (j = 0; j < i; j++)
    {
        if (strcmp(i_user, data[j].username) == 0)
        {
            if (strcmp(i_pass, data[j].password) == 0)
            {
                user_id = data[j].user_id;
                free(data);
                return user_id;
            }
        }
    }

    free(data);
    return EXIT_FAILURE;
}

