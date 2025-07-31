#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Contact {
    char name[100];
    char phone[100];
    char email[100];
}Contact;
typedef struct TreeNode {
    Contact data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
void addContact() {
    char name[100],phone[100],email[100];
    printf("Nhap ten: ");
    fgets(name,100,stdin);
    name[strcspn(name,"\n")]=0;
    printf("Nhap so dien thoai: ");
    fgets(phone,100,stdin);
    phone[strcspn(phone,"\n")]=0;
    printf("Nhap email: ");
    fgets(email,100,stdin);
    email[strcspn(email,"\n")]=0;
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    strcpy(newNode->data.name,name);
    strcpy(newNode->data.phone,phone);
    strcpy(newNode->data.email,email);
    newNode->left=NULL;
    newNode->right=NULL;
}
void displayContacs() {

}
void searchContact() {

}
void deleteContact() {

}
int main() {
    int choice;
    do {
        printf("===QUAN LY DANH BA===\n");
        printf("1.Them nguoi vao danh ba\n");
        printf("2.Hien thi danh ba theo ten\n");
        printf("3.Tim nguoi theo ten\n");
        printf("4.Xoa nguoi theo ten\n");
        printf("5.Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacs();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while (choice != 5);
    return 0;
}