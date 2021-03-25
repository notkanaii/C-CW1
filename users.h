
#ifndef UNTITLED1_USERS_H
#define UNTITLED1_USERS_H

#include <stdio.h>
#include "book_management.h"



typedef struct _User{
    char* username;
    char* password;
    struct _User* nextp;
    int books[15];
    int number;
}User;


User* CreateHuser();


void Register_account();


void Login_account();

int store_users(User* headUser);


int load_users(User* headUser);
#endif //UNTITLED1_USERS_H
