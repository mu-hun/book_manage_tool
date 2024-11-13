#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 100
#define AUTHOR_SIZE 100
#define PUBLISHER_SIZE 100

// MacOS 에서 사용 중인 GCC 컴파일러에서 gets_s 함수가 없어서 gets로 대체했습니다.
// Windows 에서는 gets_s 함수를 그대로 사용하시면 되기에 아래 정의를 주석 처리 바랍니다.
#define gets_s(s, size) gets(s)

typedef struct {
    char title[TITLE_SIZE];
    char author[AUTHOR_SIZE];
    char publisher[PUBLISHER_SIZE];
} Book;

Book books[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("도서 목록이 꽉 찼습니다.\n");
        return;
    }
    getchar();  // 엔터키를 없애기 위해서 getchar() 함수를 한 번 호출해줍니다.

    printf("> 도서의 이름: ");
    gets_s(books[book_count].title, TITLE_SIZE);

    printf("> 저자: ");
    gets_s(books[book_count].author, AUTHOR_SIZE);

    printf("> 출판사: ");
    gets_s(books[book_count].publisher, PUBLISHER_SIZE);

    printf("\n도서가 추가되었습니다.\n");
    book_count++;
}

void list_books() {
    if (book_count == 0) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    printf("등록된 모든 도서 목록을 출력합니다.\n\n");
    for (int i = 0; i < book_count; i++) {
        printf("- 도서의 이름: %s\n", books[i].title);
        printf("- 저자: %s\n", books[i].author);
        printf("- 출판사: %s\n\n", books[i].publisher);
    }
}

void search_book() {
    char search_title[TITLE_SIZE];
    int found = 0;

    getchar();  // 버퍼 비우기
    printf("> 검색할 도서의 이름을 입력해주세요 : ");
    gets_s(search_title, TITLE_SIZE);

    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title, search_title) != NULL) {
            if (found == 0) {
                printf("\n검색 결과로 다음 도서를 찾았습니다:\n");
            }
            found = 1;
            printf("- 도서의 이름: %s\n", books[i].title);
            printf("- 저자: %s\n", books[i].author);
            printf("- 출판사: %s\n\n", books[i].publisher);
        }
    }

    if (!found) {
        printf("\n검색 결과가 없습니다.\n");
    }
}

void main() {
    int choice;

    while (1) {
        printf("---\n");
        printf("1. 도서 추가\n");
        printf("2. 모든 도서 출력\n");
        printf("3. 도서 검색\n");
        printf("4. 종료\n");
        printf("\n> 수행할 항목에 대한 숫자를 입력해주세요 : ");
        scanf("%d", &choice);
        printf("---\n");

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return;
            default:
                printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
}
