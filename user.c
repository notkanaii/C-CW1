#include "book_management.h"
#include "users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void borrow_book(){};


void return_book(){};

static char *ask_question(const char *question) {

    printf("%s",question);

    const int size_step = 2;
    char *answer = malloc(size_step);
    answer[0] = 0; //now it's a string of length 0.

    //read until a new line in blocks of size_step  bytes at at time
    char *next_chunk = answer;
    int iteration = 0;
    do {
        answer = realloc(answer, size_step + iteration*size_step);
        next_chunk = answer + strlen(answer); //answer may have moved.
        fgets(next_chunk, size_step, stdin);

        next_chunk = answer + strlen(answer); //take the new read into account
        ++iteration;
    } while (* (next_chunk-1) != '\n');

    *(next_chunk-1) = 0; //truncate the string eliminating the new line.

    return answer;
}



static void lib_menu(BookArray* headNode){
    int choice = 5;
    BookArray* test;
    do {
        char * answer = ask_question("\nPlease choose an option\n1) Add a book\n2) Remove a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ");
        choice = atoi(answer);
        free(answer);
        switch (choice) {
            case 1:
                add_book(headNode);
                break;
            case 2:
                remove_book(headNode);
                break;
            case 3:
                search_book(headNode);
                break;
            case 4:
                test = headNode->pnext;
                while (test != NULL){
                    display_books(test);
                    test=test->pnext;
                }
                break;
            case 5:
                printf("Logging out...");
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }

    } while (choice != 5);
}


static void user_menu(char* uname,BookArray* headNode){
    int choice = 5;

    do {

        char * answer = ask_question("\nPlease choose an option\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ");
        choice = atoi(answer);
        free(answer);

        switch (choice) {
            case 1:
                borrow_book();
                break;
            case 2:
                return_book();
                break;
            case 3:
                search_book(headNode);
                break;
            case 4:
                display_books(headNode);
                break;
            case 5:
                printf("Logging out...");
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }

    } while (choice != 5);
}



void Register_account(User* headUser){
        User* pNewU = (User*)malloc(sizeof(User));
        pNewU->nextp = NULL;
        User* up = headUser;
        int flag = 0;
        char* name = ask_question("Please enter a username: ");
        char* word = ask_question("Please enter a password: ");
        while (headUser != NULL && up->nextp != NULL)
        {
            up = up->nextp;
            if(strcmp(name,up->username)==0){
                printf("Sorry, Register unsuccessful, the username you entered has already exist.\n");
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            free(pNewU);
        }
        if(headUser == NULL){
            headUser->nextp = pNewU;
        }
        else{
            up->nextp = pNewU;
        }
        pNewU->username = name;
        pNewU->password = word;
};


void Login_account(BookArray* headNode, User* headUser){
        char* name = ask_question("Please enter your username: ");
        char* word = ask_question("Please enter your password: ");
        char* adm = "li";
        User* up = headUser;
        if(strcmp(name, adm) == 0 && strcmp(word, adm) == 0){
            lib_menu(headNode);
        }
        else {
            while(headUser != NULL && up->nextp != NULL && strcmp(name,up->username)!= 0){
                up = up->nextp;
            }
            if(strcmp(name,up->username) == 0 && strcmp(word,up->password) == 0){
                user_menu(name,headNode);
            };
        }
};






