
#ifndef UNTITLED1_USERS_H
#define UNTITLED1_USERS_H

#include <stdio.h>



typedef struct _User{
    char* username;
    char* password;
    struct _User* nextp;
}User;


User* CreateHuser();


void Register_account();


void Login_account();
#endif //UNTITLED1_USERS_H
