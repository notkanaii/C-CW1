#include "book_management.h"
#include "users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





static char *ask_question(const char *question) {
    printf("%s",question);
    const int size_step = 2;
    char *answer = malloc(size_step);
    answer[0] = 0;
    char *next_chunk = answer;
    int iteration = 0;
    do {
        answer = realloc(answer, size_step + iteration*size_step);
        next_chunk = answer + strlen(answer);
        fgets(next_chunk, size_step, stdin);
        next_chunk = answer + strlen(answer);
        ++iteration;
    } while (* (next_chunk-1) != '\n');
    *(next_chunk-1) = 0;
    return answer;
}



static void lib_menu(BookArray* headNode){
    printf("\n(Logged as librarian)");
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
                if(headNode->pnext== NULL){//if no book stored
                    printf("No book can be removed. ");
                    break;
                }
                remove_book(headNode);
                break;
            case 3:
                search_book(headNode);
                break;
            case 4:
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\t\tCopies");
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


static void user_menu(User* up,BookArray* headNode){
    printf("\n(Logged as %s)", up->username);
    BookArray* test = NULL;//display all books
    int choice = 5;
    int id_s = 0;
    int check_r = 0;
    int flag = 0;
    BookArray *p = NULL;

    do {

        char * answer = ask_question("\nPlease choose an option\n1) Borrow a book\n2) Return a book\n3) Search for books\n4) Display all books\n5) Log out\n Option: ");
        choice = atoi(answer);
        free(answer);

        switch (choice) {
            case 1:

                id_s = atoi(ask_question("Enter the book id you want to borrow: "));
                if(id_s==0){
                    printf("\nSorry, the id is invalid. ");
                    break;
                }
                while (check_r <= up->number) { //check if the books repeat
                    if (up->books[check_r] == id_s) {
                        printf("\nSorry, you have already borrowed this book. ");
                        flag = 1;
                        break;
                    }
                    check_r++;
                }
                check_r = 0;
                if(flag == 1) {
                    flag = 0;
                    continue;
                }
                p = find_book_by_id(id_s, headNode);
                if (p == NULL) {
                    printf("\nSorry, the id is invalid. ");
                    continue;
                }
                else borrow_book(up, p);
                continue;
            case 2:
                if(up->books[0] ==0){
                    printf("You haven't borrow any book. ");
                    continue;
                }
                return_book(up, headNode);
                continue;
            case 3:
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies");
                search_book(headNode);
                continue;
            case 4:
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies");
                test = headNode->pnext;
                while (test != NULL){
                    display_books(test);
                    test=test->pnext;
                }
                continue;
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
    pNewU->number = 0;
    User* up = headUser;
    int flag = 0;
    char* name = ask_question("Please enter a username: ");
    char* word = ask_question("Please enter a password: ");
    while (headUser != NULL && up->nextp != NULL)
    {
        up = up->nextp;
        if(strcmp(name,up->username)==0){
            printf("\nSorry, Register unsuccessful, the username you entered has already exist.\n");
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        free(pNewU);
    }else{
        if(headUser == NULL){
            headUser->nextp = pNewU;
        }
        else{
            up->nextp = pNewU;
        }
        for(int i = 0;i<10;i++){
            pNewU->books[i]=0;
        }
        pNewU->username = name;
        pNewU->password = word;
        printf("\nRegister succeeded. ");
    }

};


void Login_account(BookArray* headNode, User* headUser){
    char* name = ask_question("Please enter your username: ");
    char* word = ask_question("Please enter your password: ");
    char* adm = "li";
    User* up = headUser;
    if(strcmp(name, adm) == 0 && strcmp(word, adm) == 0){
        lib_menu(headNode);
    }//login as librarian
    else {
        while(headUser != NULL && up->nextp != NULL && strcmp(name,up->username)!= 0){
            up = up->nextp;
        }
        if(strcmp(name,up->username) == 0 && strcmp(word,up->password) == 0){
            user_menu(up,headNode);
        }else{
            printf("\nLogin unsuccessful. Please check your username and password. \n");
        }
    }
};






