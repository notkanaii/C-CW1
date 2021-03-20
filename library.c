#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"



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


int store_books(BookArray* headNode){
    FILE*fp;
    if ((fp=fopen("library.txt","r"))==NULL)
    {
        fp=fopen("library.txt","w");
        fclose(fp);
    }
    fp = fopen("library.txt", "w");
    BookArray *p = headNode;
    while (p != NULL)
    {
        fwrite(p, sizeof(BookArray), 1, fp);
        p = p->pnext;
    }
    fclose(fp);
    return 0;
}


int add_book(BookArray* headNode){
    BookArray* pNewA = (BookArray*)malloc(sizeof(BookArray));
    pNewA->pnext =NULL;
    pNewA->array.id = atoi(ask_question("input book id: "));
    pNewA->array.title = ask_question("input book title: ");
    pNewA->array.authors = ask_question("input book authors: ");
    pNewA->array.year = atoi(ask_question("input book year: "));
    pNewA->array.copies = atoi(ask_question("input book copies: "));
    BookArray*p = headNode;
    while (headNode!= NULL && p->pnext != NULL)
    {
        p = p->pnext;
    }
    if (headNode == NULL) {
        headNode->pnext = pNewA;
    }
    else {
        p->pnext = pNewA;
    }
    return 0;
}


int load_books(BookArray* headNode){
    FILE*fp;
    fp = fopen("library.txt","r");
    BookArray* last = (BookArray*)malloc(sizeof(BookArray));
    last = headNode;
    while (!feof(fp)) {
        BookArray* pn = (BookArray*)malloc(sizeof(BookArray));
        if(last->pnext == NULL) headNode->pnext = pn;
        fread(pn,sizeof(BookArray),1,fp);
        last->pnext=pn;
        last=pn;
        pn->pnext = NULL;
    }
    if(headNode->pnext != NULL) return 0;
}

int remove_book(BookArray* headNode){
    BookArray* pb = headNode;//遍历节点
    BookArray* pbefore = headNode;//前一个节点跟随
}

void search_book(BookArray* headNode){
    int choice0 = 4;
    int yearnumber = 0;
    int flag = 0;
    do {
        char * answer = ask_question("\nPlease choose an option\n1) Find books by title \n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
        choice0 = atoi(answer);
        free(answer);
        switch (choice0) {
            case 1: {
                BookArray* find = createHead();
                BookArray* follow = NULL;
                BookArray* first = NULL;
                char *title = ask_question("Please enter title: ");
                find = find_book_by_title(title, headNode);
                first = find;
                follow = find->pnext;
                while(find->pnext != NULL){
                    find->pnext = find_book_by_title(title, follow);
                    follow = find;
                }
                while (first != NULL){
                    display_books(first);
                    first = first->pnext;
                }
            }
            case 2: {
                char *author = ask_question("Please enter author: ");
                find_book_by_author(author, headNode);
                free(author);
            }
            case 3: {
                char *year = ask_question("Please enter year: ");
                yearnumber = atoi(year);
                find_book_by_year(yearnumber, headNode);
                free(yearnumber);
            }
            case 4:
                flag = 1;
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }
    while (choice0 != 4);
}


BookArray* find_book_by_title (const char *title,BookArray* headNode){
    BookArray* pfind = headNode;
    while(strcmp(title,pfind->array.title)!=0){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
    }
    return pfind;
}


BookArray* find_book_by_author (const char *author, BookArray* headNode){
    BookArray* pfind = headNode;
    while(strcmp(author,pfind->array.authors)!=0){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
    }
    return pfind;
}


BookArray* find_book_by_year (unsigned int year,BookArray* headNode){
    BookArray* pfind = headNode;
    while(year!=pfind->array.year){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
    }
    return pfind;
}


int display_books(BookArray* headNode){
    if (headNode->array.id = 0) return 0;
    printf("%i\t%s\t%s\t%i\t%i",
           headNode->array.id,
           headNode->array.title,
           headNode->array.authors,
           headNode->array.year,
           headNode->array.copies);
}

