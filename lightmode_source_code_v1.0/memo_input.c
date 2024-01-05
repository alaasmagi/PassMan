/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "main_db.h"
#include "memo_input.h"
#include "file_encryption.h"
#include "file_decryption.h"

int AddInputToFile(user_entry *input_db, char *passcheck, int user_id)
{
    char filename[MAX_LEN];
    snprintf(filename, sizeof(filename), "%d.db", user_id);
    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    if (strcmp(input_db[0].userpass, passcheck) != 0)
    {
        return 1;
    }
    FileDecrypt(user_id, filename);
    rc = sqlite3_open(filename, &db);
    if (db == NULL) 
    {
        fprintf(stderr, "Tõrge: %s!\n", errMsg);
        sqlite3_close(db);
        return EXIT_FAILURE;
    }
    
    char *sql = sqlite3_mprintf("INSERT INTO user_memo (id, u_title, "
                                    "e_url, u_email, u_pass) "
                                "VALUES (%d, '%s', '%s', '%s', '%s');",
    input_db[0].index, input_db[0].title, input_db[0].environment_url, 
    input_db[0].user_email, input_db[0].userpass);
    
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        printf("Tõrge: %s\n", errMsg);
        
        sqlite3_free(errMsg);
        sqlite3_close(db);
        
        return EXIT_FAILURE;
    }
    sqlite3_close(db);
    free(input_db);
    FileEncrypt(user_id, filename);
    
    return EXIT_SUCCESS;
    
}
