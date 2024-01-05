/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "main_db.h"
#include "memo_search.h"
#include "file_decryption.h"
#include "file_encryption.h"

// Callback function for SQLite3 query
/*static int searchCallback(void *resultPtr, int argc, char **argv,
                                                                char **colNames)
{
    if (argc != 5)
    {
        return 1;
    }
    user_entry *result = (user_entry *)resultPtr;
    result->index = atoi(argv[0]);
    snprintf(result->title, sizeof(result->title), "%s", argv[1]);
    snprintf(result->environment_url, sizeof(result->environment_url), "%s",
    argv[2]);
    snprintf(result->user_email, sizeof(result->user_email), "%s", argv[3]);
    snprintf(result->userpass, sizeof(result->userpass), "%s", argv[4]);
    return 0;
}*/

// Function to search for a user by name
void searchByPhrase(user_entry **data, const char *searchPhrase, int user_id)
{
    // Open the SQLite3 database
    char filename[MAX_LEN];
    snprintf(filename, sizeof(filename), "%d.db", user_id);
    FileDecrypt(user_id, filename);
  
    sqlite3 *db;
    int rc = sqlite3_open(filename, &db);
    user_entry result[1];
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    
    // Prepare the query
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, "SELECT * FROM user_memo WHERE u_title LIKE ?", -1, &stmt, NULL);
    if (rc != SQLITE_OK) 
    {
        fprintf(stderr, "Error preparing query: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    // Bind the search phrase to the query
    rc = sqlite3_bind_text(stmt, 1, searchPhrase, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) 
    {
        fprintf(stderr, "Error binding search phrase: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    // Execute the query
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) 
    {
        result->index = sqlite3_column_int(stmt, 0);
        snprintf(result->title, sizeof(result->title), "%s", sqlite3_column_text(stmt, 1));
        snprintf(result->environment_url, sizeof(result->environment_url), "%s", sqlite3_column_text(stmt, 2));
        snprintf(result->user_email, sizeof(result->user_email), "%s", sqlite3_column_text(stmt, 3));
        snprintf(result->userpass, sizeof(result->userpass), "%s", sqlite3_column_text(stmt, 4));
    }
    else if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Error executing query: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    FileEncrypt(user_id, filename);
    **data = *result;
}




