/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#ifndef HASH_H
#define HASH_H
#include "main_db.h"

void hash_string(const char* str, unsigned char* digest, 
                                    unsigned int* digest_len);
char* PassHash(char *hashable); 

#endif // HASH_H
