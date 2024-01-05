/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#ifndef MEMO_SEARCH_H
#define MEMO_SEARCH_H
#include "main_db.h"

/*static int searchCallback(void *resultPtr, int argc, char **argv, 
                                                            char **colNames);*/
void searchByPhrase(user_entry **data, const char *searchPhrase, int user_id);

#endif //MEMO_SEARCH_H
