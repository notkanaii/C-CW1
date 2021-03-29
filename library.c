#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "book_management.h"


static char *ask_question(const char *question) {
    printf("%s", question);
    const int size_step = 2;
    char *answer = malloc(size_step);
    answer[0] = 0;
    char *next_chunk = answer;
    int iteration = 0;
    do {
        answer = realloc(answer, size_step + iteration * size_step);
        next_chunk = answer + strlen(answer);
        fgets(next_chunk, size_step, stdin);
        next_chunk = answer + strlen(answer);
        ++iteration;
    } while (*(next_chunk - 1) != '\n');
    *(next_chunk - 1) = 0;
    return answer;
}


int nonumber(char* str){ //make sure no number in string
    char* p = str;
    int check = 0;
    while (check==0 && *p){
        if(*p>='0'&&*p<='9') check = 1;
        p++;
    }
    return(check?1:0);
}


BookArray *find_book_by_title(const char *title, BookArray *headNode) {
    BookArray *pfind = headNode;
    while (pfind != NULL && strcmp(title, pfind->array.title) != 0) {
        pfind = pfind->pnext;
    }
    return pfind;
}


BookArray *find_book_by_author(const char *author, BookArray *headNode) {
    BookArray *pfind = headNode;
    while (pfind != NULL && strcmp(author, pfind->array.authors) != 0) {
        pfind = pfind->pnext;
    }
    return pfind;
}


BookArray *find_book_by_year(int year, BookArray *headNode) {
    BookArray *p = headNode;
    while (p != NULL && year != p->array.year) {
        p = p->pnext;
    }
    return p;
}


BookArray *find_book_by_id(int id, BookArray *headNode) {
    BookArray *p = headNode->pnext;
    while (p != NULL && id != p->array.id) {
        p = p->pnext;
    }
    return p;
}

void borrow_book(User user, BookArray *book) {
    if (book->array.copies > 0 && user.number < 10) { //the number of books can a student borrow
        book->array.copies--;
        user.books[user.number] = book->array.id;
        user.number++;
        printf("Borrowed succeeded. \n");
    } else {
        printf("Sorry, you can not borrow this book. ");
    }
}


void return_book(User *user, BookArray *headNode) {
    int n = 0;
    int i = 0;
    int s = 0;
    int f = 0; //flag
    BookArray *pi = NULL;
    pi = headNode->pnext;
    printf("\nThe books id you have borrowed: ");
    while (n < user->number) {
        printf("\n%i", user->books[n]);
        n++;
    }
    n = 0;
    int answer = atoi(ask_question("\nThe id of book you want to return: "));
    while (n < user->number) {
        if (user->books[n] == answer) {
            f = 1;
            s = user->books[n];
            i = n;
            while (i < user->number) {
                user->books[i] = user->books[i + 1];
                i++;
            }
            user->number--;
            break;
        }
        n++;
    }
    while (pi) {
        if (s == pi->array.id) {
            pi->array.copies++;
            break;
        }
        pi = pi->pnext;
    }
    if(f) printf("Return succeeded. \n");
    else printf("Invalid id. \n");
}

void check_length(char *words){
    if(strlen(words)<4){
        printf("\t\t\t\t\t\t");
    }else if(strlen(words)>=4&&strlen(words)<8){
        printf("\t\t\t\t\t");
    }else if(strlen(words)<12&&strlen(words)>=8){
        printf("\t\t\t\t");
    }else if(strlen(words)<16&&strlen(words)>=12){
        printf("\t\t\t");
    }else if(strlen(words)>=16&&strlen(words)<20){
        printf("\t\t");
    }else{
        printf("\t");
    }
}


int display_books(BookArray *headNode) {
    if (headNode->array.id == 0) return 0;
    printf("\n");
    printf("%i\t",headNode->array.id);
    printf("%s",headNode->array.title);
    check_length(headNode->array.title);
    printf("%s",headNode->array.authors);
    check_length(headNode->array.authors);
    printf("%i\t",headNode->array.year);
    printf("%i",headNode->array.copies);
    return 0;
}


int add_book(BookArray *headNode) {
    BookArray *pNewA = (BookArray *) malloc(sizeof(BookArray));
    int flag = 0;
    int a = 0;
    a = atoi(ask_question("input book id: "));
    BookArray *check = headNode;
    while (check) {
        if (check->array.id == a) {
            flag = 1;
            break;
        }
        check = check->pnext;
    }
    if (flag == 1||a==0) {
        free(pNewA);
        printf("\nSorry, the id is invalid. \n");
        return 0;
    } else {
        pNewA->array.id = a;
        pNewA->pnext = NULL;
        pNewA->searchlink = NULL;
        pNewA->array.title = ask_question("input book title: ");
        pNewA->array.authors = ask_question("input book authors: ");
        pNewA->array.year = atoi(ask_question("input book year: "));
        pNewA->array.copies = atoi(ask_question("input book copies: "));
        BookArray *p = headNode;
        if(pNewA->array.year==0||pNewA->array.copies==0){
            printf("\nInvalid year or copies. \n");
            free(pNewA);
            return 0;
        }
        if(nonumber(pNewA->array.authors)){
            printf("\nInvalid authors. \n");
            free(pNewA);
            return 0;
        }
        while (headNode != NULL && p->pnext != NULL) {
            p = p->pnext;
        }
        if (headNode->pnext == NULL) {
            headNode->pnext = pNewA;
        } else {
            p->pnext = pNewA;
        }
        return 0;
    }
}


int store_books(BookArray *headNode) {
    FILE *fp;
    BookArray *p = headNode->pnext;
    fp = fopen("file.txt", "wb");
    while (p) {
        //printf("\nAAAAAAA");
        fwrite(&(p->array.id), sizeof(int), 1, fp);
        fwrite(p->array.title, 50 * sizeof(char), 1, fp);
        fwrite(p->array.authors, 50 * sizeof(char), 1, fp);
        fwrite(&(p->array.year), sizeof(int), 1, fp);
        fwrite(&(p->array.copies), sizeof(int), 1, fp);
        p = p->pnext;
    }
    fclose(fp);
    return 0;
}


int load_books(BookArray *headNode) {
    FILE *fp;
    BookArray *qn = headNode;
    // if no this file, create
    if ((fp = fopen("file.txt", "rb")) == NULL) {
        fp = fopen("file.txt", "wb");
        fclose(fp);
    }
    fp = fopen("file.txt", "rb");
    int a = 0;
    while (fread(&a, sizeof(int), 1, fp)) {
        BookArray *pn = (BookArray *) malloc(sizeof(BookArray));
        pn->pnext = NULL;
        pn->searchlink =NULL;
        pn->array.title = (char *) malloc(50 * sizeof(char));
        pn->array.authors = (char *) malloc(50 * sizeof(char));
        //ensure nothing in the string
        memset(pn->array.title, 0,50*sizeof(char));
        memset(pn->array.authors, 0,50*sizeof(char));
        //fread(&(pn->array.id),sizeof(int),1,fp);
        pn->array.id = a;
        fread(pn->array.title, 50 * sizeof(char), 1, fp);
        fread(pn->array.authors, 50 * sizeof(char), 1, fp);
        fread(&(pn->array.year), sizeof(int), 1, fp);
        fread(&(pn->array.copies), sizeof(int), 1, fp);
        qn->pnext = pn;
        qn = pn;
        if (feof(fp)) break;
    }
    if (headNode->pnext != NULL) return 0;
    fclose(fp);
}


int store_users(User *headUser) {
    FILE *fp;
    User *p = headUser->nextp;
    fp = fopen("user.txt", "wb");
    while (p) {
        //printf("\nAAAAAAA");        //check for the loop
        fwrite(&(p->number), sizeof(int), 1, fp);
        fwrite(p->username, 50 * sizeof(char), 1, fp);
        fwrite(p->password, 50 * sizeof(char), 1, fp);
        for (int i = 0; i < 10; i++) {
            fwrite(&(p->books[i]), sizeof(int), 1, fp);
        }
        p = p->nextp;
    }
    fclose(fp);
    return 0;
}


int load_users(User *headUser) {
    FILE *fp;
    User *qn = headUser; //follow the node
    if ((fp = fopen("user.txt", "rb")) == NULL) {
        fp = fopen("user.txt", "wb");
        fclose(fp);
    }
    fp = fopen("user.txt", "rb");
    int a = 0;
    while (fread(&a, sizeof(int), 1, fp)) {
        User *pn = (User *) malloc(sizeof(User));
        pn->number = a;
        pn->nextp = NULL;
        pn->username = (char *) malloc(50 * sizeof(char));
        pn->password = (char *) malloc(50 * sizeof(char));
        fread(pn->username, 50 * sizeof(char), 1, fp);
        fread(pn->password, 50 * sizeof(char), 1, fp);
        for (int i = 0; i < 10; i++) {

            fread(&(pn->books[i]), sizeof(int), 1, fp);

        }
        qn->nextp = pn;
        qn = pn;
    }
    if (headUser->nextp != NULL) return 0;
    fclose(fp);
}


int remove_book(BookArray *headNode) {
    int as = atoi(ask_question("Please enter the book id you want to remove: "));
    BookArray *pfind = headNode->pnext;
    BookArray *before;
    if (pfind->array.id == as) {
        headNode->pnext = pfind->pnext;
        free(pfind);
        printf("\nRemove succeeded. ");
        return 0;
    } else {
        while (as != pfind->array.id) {
            before = pfind;
            pfind = pfind->pnext;
            if (pfind==NULL) break;
        }
        if (before != NULL && pfind != NULL) {
            before->pnext = pfind->pnext;
            free(pfind);
            printf("\nRemove succeeded. ");
            return 0;
        }
    }
    //If not find the book id
    printf("\nInvalid id. ");
    return 0;
}

void search_book(BookArray *headNode) {
    int choice0 = 4;
    int flag = 0;
    do {
        char *answer = ask_question(
                "\nPlease choose an option\n1) Find books by title \n2) Find books by author\n3) Find books by year\n4) Return to previous menu\n Option: ");
        choice0 = atoi(answer);
        free(answer);
        switch (choice0) {
            case 1: {
                BookArray *find = NULL;
                BookArray *follow = NULL;
                BookArray *first = NULL;  //output the results
                BookArray *clear = NULL;
                char *title = ask_question("Please enter title: ");
                find = find_book_by_title(title, headNode->pnext);
                first = find;
                clear = first;
                follow = find;
                while (find != NULL) {
                    find = find->pnext;
                    find = find_book_by_title(title, find);
                    if (find == NULL) {
                        break;
                    }
                    follow->searchlink = find;
                    follow = follow->searchlink;
                }
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies");
                while (first != NULL) {
                    display_books(first);
                    first = first->searchlink;
                    clear->searchlink = NULL;
                    clear = first;
                }
                printf("\n");
                break;
            }
            case 2: {
                BookArray *find = NULL;
                BookArray *follow = NULL;
                BookArray *first = NULL;
                BookArray *clear = NULL;
                char *author = ask_question("Please enter author: ");
                find = find_book_by_author(author, headNode->pnext);
                if(nonumber(author)){
                    printf("Invalid author. ");
                    break;
                }
                first = find;
                clear = first;
                follow = find;
                while (find != NULL) {
                    find = find->pnext;
                    find = find_book_by_author(author, find);
                    if (find == NULL) {
                        break;
                    }
                    follow->searchlink = find;
                    follow = follow->searchlink;
                }
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies");
                while (first != NULL) {
                    display_books(first);
                    first = first->searchlink;
                    clear->searchlink = NULL;
                    clear = first;
                }
                printf("\n");

                break;
            }
            case 3: {
                BookArray *find = NULL;
                BookArray *follow = NULL;
                BookArray *first = NULL;
                BookArray *clear = NULL;
                int year = atoi(ask_question("Please enter year: "));
                if(year == 0){
                    printf("Invalid year. ");
                    break;
                }
                find = find_book_by_year(year, headNode->pnext);
                first = find;
                clear = find;
                follow = find;
                while (find != NULL) {
                    find = find->pnext;
                    find = find_book_by_year(year, find);
                    if (find == NULL) {
                        break;
                    }
                    follow->searchlink = find;
                    follow = follow->searchlink;

                }
                printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies");
                // Clear the searchlink
                while (first != NULL) {
                    display_books(first);
                    first = first->searchlink;
                    clear->searchlink = NULL;
                    clear = first;
                }
                printf("\n");
                break;
            }
            case 4:
                break;
            default:
                printf("Sorry, the option you entered was invalid, please try again\n");
        }
    } while (choice0 != 4);
}


