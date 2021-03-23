
#ifndef UNTITLED1_USERS_H
#define UNTITLED1_USERS_H

#include <stdio.h>
#include "book_management.h"



typedef struct _User{
    char* username;
    char* password;
    struct _User* nextp;
    Book books[10];
    int number;
}User;


User* CreateHuser();


void Register_account();


void Login_account();
#endif //UNTITLED1_USERS_H
