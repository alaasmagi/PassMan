/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include <openssl/evp.h>
#include <string.h>
#include <stdio.h>
#include "hash.h"

void hash_string(const char* str, unsigned char* digest, 
                                    unsigned int* digest_len);

char* PassHash(char *hashable) 
{
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len = 0;
    hash_string(hashable, digest, &digest_len);
    
    char* result = (char*) malloc(digest_len * 2 + 1);
    if (result == NULL) 
    {
        return NULL; 
    }
    
    for (int i = 0; i < digest_len; i++) 
    {
        sprintf(result + i * 2, "%02x", digest[i]); 
    }
    result[digest_len * 2] = '\0'; 
    
    return result;
}

void hash_string(const char* str, unsigned char* digest, 
                                    unsigned int* digest_len) 
{
    // Initialize the OpenSSL library
    OpenSSL_add_all_digests();

    // Create a SHA256 hash context
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    const EVP_MD* md = EVP_sha256();

    // Initialize the context
    EVP_DigestInit_ex(mdctx, md, NULL);

    // Hash the input string
    size_t len = strlen(str);
    EVP_DigestUpdate(mdctx, str, len);

    // Finalize the hash computation and get the result
    EVP_DigestFinal_ex(mdctx, digest, digest_len);

    // Clean up the hash context
    EVP_MD_CTX_free(mdctx);

    // Clean up the OpenSSL library
    EVP_cleanup();
}





