/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#ifndef MAIN_DB_H
#define MAIN_DB_H

#define PSW_MIN_LEN 8
#define MAX_LEN 150
#define URL_MAX_LEN 255
#define MAIN_USERS "main_users.txt"

typedef struct {
    int user_id;
    char username[MAX_LEN];
    char password[MAX_LEN];
} main_users;

typedef struct {
    int index;
    char title[MAX_LEN];
    char environment_url[URL_MAX_LEN];
    char user_email[MAX_LEN];
    char userpass[MAX_LEN];
} user_entry;

#endif //MAIN_DB_H
