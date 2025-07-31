#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char chuoi[100];
    int top;
}clipBoardStack;
typedef struct {
    clipBoardStack data;
    int top;
}redoStack;
clipBoardStack *createClipBoard() {
    clipBoardStack *stack = (clipBoardStack *)malloc(sizeof(clipBoardStack));
    stack->top = 0;
    return stack;
}
redoStack *createRedo() {
    redoStack *stack = (redoStack *)malloc(sizeof(redoStack));
    stack->top = 0;
    return stack;
}
void copy() {
    clipBoardStack *stack = createClipBoard();
    char chuoi[100];
    printf("Nhap mot chuoi: ");
    fgets(chuoi,100,stdin);
    chuoi[strcspn(chuoi,"\n")]=0;
    strcspn(chuoi,"\r");
    stack->top = stack->top+1;
    printf("Them thanh cong\n");
}
void paste() {

}
void undo() {

}
void redo() {

}
void printAll() {

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