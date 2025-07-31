#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char chuoi[100];
}clipEnter;
typedef struct {
    clipEnter data[100];
    int top;
}clipBoardStack;
typedef struct {
    clipEnter data[100];
    int top;
}redoStack;

clipBoardStack clipBoard;
redoStack reDo;
void copy() {
    clipBoard.top=0;
    if (clipBoard.top >= 100) {
        printf("Clipboard full!\n");
        return;
    }
    char chuoi[100];
    printf("Nhap mot chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strcspn(chuoi, "\n")] = '\0';
    strcpy(clipBoard.data[clipBoard.top].chuoi, chuoi);
    clipBoard.top++;
    printf("Them thanh cong\n");
}
void paste() {
    if (clipBoard.top == 0) {
        printf("Clipboard is empty!\n");
        return;
    }
    printf("Paste: %s\n", clipBoard.data[clipBoard.top - 1].chuoi);
}
void undo() {
    if (clipBoard.top == 0) {
        printf("Nothing to undo!\n");
        return;
    }
    reDo.data[reDo.top++]=clipBoard.data[--clipBoard.top];
    printf("Undo complete\n");
}
void redo() {
    if (reDo.top == 0) {
        printf("Nothing to redo!\n");
        return;
    }
    clipBoard.data[clipBoard.top++]=reDo.data[--reDo.top];
    printf("redo complete\n");
}
void printAll() {
    printf("ALL CLIPBOARD\n");
    if (clipBoard.top == 0) {
        printf("Empty\n");
    }else {
        for (int i = 0;i<clipBoard.top;i++) {
            printf("%d. %s\n", i + 1, clipBoard.data[i].chuoi);
        }
    }
}
int main() {
    int choice;
    do {
        printf("=====CLIPBOARD MANAGER=====\n");
        printf("1.COPY\n");
        printf("2.PASTE\n");
        printf("3.UNDO\n");
        printf("4.REDO\n");
        printf("5.Hien thi\n");
        printf("6.Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        switch (choice) {
            case 1:
                copy();
                break;
            case 2:
                paste();
                break;
            case 3:
                undo();
                break;
            case 4:
                redo();
                break;
            case 5:
                printAll();
                break;
            case 6:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");\
                break;

        }
    }while (choice != 6);
    return 0;
}