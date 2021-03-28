#include "book_management.h"
#include "interface.h"
#include "users.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


BookArray * createHead(){
    BookArray* headNode = (BookArray*)malloc(sizeof(BookArray));
    headNode->pnext = NULL;
    headNode->length = 0;
    headNode->searchlink =NULL;
    headNode->array.id = 0;
    return headNode;
}

User* CreateHuser(){
    User* headUser = (User*)malloc(sizeof(User));
    headUser->nextp = NULL;

    return headUser;
};


static void main_menu(BookArray* headNode, User* headUser) {
    BookArray* test = NULL;
    int choice = 5;

    do {

        char * answer = ask_question("\nPlease choose an option\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\n Option: ");
        choice = atoi(answer);
        free(answer);

        switch (choice) {
            case 1:
                Register_account(headUser);
                break;
            case 2:
                Login_account(headNode,headUser);
                break;
            case 3:
                search_book(headNode);
                break;
            case 4:
                test = headNode->pnext;
                printf("\nID\tTitle\t\t\t\tAuthors\t\t\t\tYear\t\tCopies");
                while (test != NULL){
                    display_books(test);
                    test=test->pnext;
                }
                printf("\n");
                break;
            case 5:
                printf("Thank you for using the library!\nGoodbye!");
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }

    } while (choice != 5);

}

int main(){
    BookArray* headNode = createHead();
    User* headUser = CreateHuser();
    BookArray* f1 = NULL;
    User* f2 = NULL;
    load_users(headUser);
    load_books(headNode);
    main_menu(headNode, headUser);
    store_books(headNode);
    store_users(headUser);
    while(headNode){
        f1 = headNode;
        headNode = headNode->pnext;
        free(f1);
    }
    while(headUser){
        f2 = headUser;
        headUser = headUser->nextp;
        free(f2);
    }
    return 0;
}