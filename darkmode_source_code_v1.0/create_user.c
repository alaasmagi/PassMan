/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "memo_input.h"
#include "create_user.h"
#include "hash.h"
#include "file_encryption.h"


int CreateUserAccount(char *looKasutaja_E, char *looPass_E, char *uusPassKinnita_E)
{
    main_users *database = (main_users*)malloc(sizeof(main_users));
    main_users *compDb = (main_users*)malloc(sizeof(main_users));
    main_users *tempDb = NULL;
    
    int user_id_buf;
    char username_buf[MAX_LEN];
    char psw_buf[MAX_LEN];
    
    int i, j;
    int user_id;
    char file_name[MAX_LEN];
    srand(time(0));
    user_id = time(0);
    database[0].user_id = user_id;
    snprintf(file_name, sizeof(file_name), "%d.db", user_id);
    if (strlen(looPass_E) < PSW_MIN_LEN)
    {
        printf("Salasõna pikkus peab olema vähemalt 8 tähemärki, korrake sisestust!\n");
        free(database);
        return 2;
    }
    if (strcmp(looPass_E, uusPassKinnita_E) != 0)
    {
        printf("Salasõnad ei kattu, korrake sisestust!\n");
        free(database);
        return 3;
    }
    strcpy(database[0].username, looKasutaja_E);
    looPass_E = PassHash(looPass_E);
    strcpy(database[0].password, looPass_E);
    
    FILE *fp;
    fp = fopen(MAIN_USERS, "a+");
    if (fp == NULL)
    {
        fprintf(stderr, "Tõrge faili avamisel!\n");
        return EXIT_FAILURE;
    }

    i = 0;
    while (fscanf(fp, "%d %s %s", &user_id_buf, username_buf, psw_buf) != EOF)
    {
        tempDb = realloc(compDb, sizeof(main_users) * (i + 1));
        if (tempDb == NULL) 
        {
            fprintf(stderr, "Tõrge mälu andmisel!\n");
            fclose(fp);
            return EXIT_FAILURE;
        }
        compDb = tempDb;
        (compDb + i)->user_id = user_id_buf;
        strcpy((compDb + i)->username, username_buf);
        strcpy((compDb + i)->password, psw_buf);
        
        if ((compDb + i)->username == NULL || (compDb + i)->password == NULL)
        {
            printf("Mälu andmisel tekkis tõrge.\n");
			break;
        }
        
        i++;
        
    }
    for (j = 0; j < i; j++)
    {
        if (strcmp(looKasutaja_E, compDb[j].username) == 0)
        {
            printf("Selline kasutajanimi juba eksisteerib!\n");
            free(compDb);
            fclose(fp);
            return 4;
        }
    }
    
    fprintf(fp, "%d %s %s\n", database[0].user_id, database[0].username, database[0].password);
    
    fclose(fp);
        
    UserFileCreation(file_name);
    FileEncrypt(user_id, file_name);
    free(compDb);
    free(database);
    return EXIT_SUCCESS;
}


int UserFileCreation(char *filename)
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    
    rc = sqlite3_open(filename, &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Andmebaasi ei suudetud avada: %s\n", 
                                                            sqlite3_errmsg(db));
        sqlite3_close(db);
        return EXIT_FAILURE;
    }
    
    char *sql = "CREATE TABLE user_memo ("
                "id INTEGER(10),"
                "u_title VARCHAR(100),"
                "e_url VARCHAR(255),"
                "u_email VARCHAR(100),"
                "u_pass VARCHAR(100));";
                
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK)
    {
        printf("ERROR: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
    
}










