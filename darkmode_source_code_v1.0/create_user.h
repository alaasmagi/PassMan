/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#ifndef CREATE_USER_H
#define CREATE_USER_H
#include "main_db.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "memo_input.h"

int CreateUserAccount(char *looKasutaja_E, 
                                    char *looPass_E, char *uusPassKinnita_E);
int UserFileCreation(char *filename);

#endif //CREATE_USER_H
