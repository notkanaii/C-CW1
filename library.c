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


BookArray* find_book_by_title (const char *title,BookArray* headNode){
    BookArray* pfind = headNode;
    if(strcmp(title,pfind->array.title) == 0) return pfind;
    while(strcmp(title,pfind->array.title)!=0){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
        if(strcmp(title,pfind->array.title) == 0) return pfind;
    }
    return pfind;
}


BookArray* find_book_by_author (const char *author, BookArray* headNode){
    BookArray* pfind = headNode;
    if(strcmp(author,pfind->array.authors) == 0) return pfind;
    while(strcmp(author,pfind->array.authors) != 0){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
        if(strcmp(author,pfind->array.authors) == 0) return pfind;
    }
    return pfind;
}


BookArray* find_book_by_year (int year,BookArray* headNode){
    BookArray* pfind = headNode->pnext;
    if(pfind->array.year == year) return pfind;
    while(year!=pfind->array.year){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
        if(pfind->array.year == year) return pfind;
    }
    return NULL;
}

BookArray* find_book_by_id (int id,BookArray* headNode){
    BookArray* pfind = headNode->pnext;
    if(pfind->array.id == id) return pfind;
    while(id!=pfind->array.id){
        pfind = pfind->pnext;
        if(pfind->pnext == NULL) return NULL;
        if(pfind->array.id == id) return pfind;
    }
    return NULL;
}



int display_books(BookArray* headNode){
    if (headNode->array.id == 0) return 0;
    printf("%i\t%s\t%s\t%i\t%i\n",
           headNode->array.id,
           headNode->array.title,
           headNode->array.authors,
           headNode->array.year,
           headNode->array.copies);
    return 0;
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
    pNewA->searchlink=NULL;
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
    search_book(headNode);
    int as = atoi(ask_question("Please enter the book id you want to remove: "));
    BookArray* pfind = headNode->pnext;
    BookArray* before;
    if(pfind->array.id == as) {
        headNode->pnext = pfind->pnext;
        free(pfind);
    }
    else {
        while(as!=pfind->array.id){
            before = pfind;
            pfind = pfind->pnext;
        }
        if(before!=NULL && pfind!=NULL){
            before->pnext = pfind->pnext;
            free(pfind);
        }
    }
    return 0;
}

void search_book(BookArray* headNode){
    int choice0 = 4;
    int flag = 0;
    do {
        char * answer = ask_question("\nPlease choose an option\n1) Find books by title \n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
        choice0 = atoi(answer);
        free(answer);
        switch (choice0) {
            case 1: {
                BookArray* find = createHead();
                BookArray* follow;
                BookArray* first;
                char *title = ask_question("Please enter title: ");
                find = find_book_by_title(title, headNode);
                first = find;
                follow = find;
                while(find->pnext != NULL){
                    find->pnext = find_book_by_title(title, follow);
                    follow = find;
                }
                while (first != NULL){
                    display_books(first);
                    first = first->pnext;
                    follow->searchlink= find;
                    if(follow->searchlink==NULL) break;
                    follow = follow->searchlink;
                    find = find->pnext;
                }
                while (first != NULL){
                    display_books(first);
                    first = first->searchlink;
                }
                break;
            }
            case 2: {
                BookArray* find = createHead();
                BookArray* follow;
                BookArray* first;
                char *author = ask_question("Please enter author: ");
                find = find_book_by_author(author, headNode);
                first = find;
                follow = find;
                while(find!= NULL){
                    find = find_book_by_author(author, headNode);
                    follow->searchlink= find;
                    if(follow->searchlink==NULL) break;
                    follow = follow->searchlink;
                    find = find->pnext;
                }
                while (first != NULL){
                    display_books(first);
                    first = first->searchlink;
                }
                break;
            }
            case 3: {
                BookArray* find;
                BookArray *follow = NULL;
                BookArray* first;
                int year = atoi(ask_question("Please enter year: "));
                find = find_book_by_year(year, headNode);
                first = find;
                follow = find;
                while(find!= NULL){
                    find = find_book_by_year(year, find);
                    follow->searchlink= find;
                    if(follow->searchlink==NULL) break;
                    follow = follow->searchlink;
                    find = find->pnext;
                }
                while (first != NULL){
                    display_books(first);
                    first = first->searchlink;
                }
                break;
            }
            case 4:
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }
    }
    while (choice0 != 4);
}


