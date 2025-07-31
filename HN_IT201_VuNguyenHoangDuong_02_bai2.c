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
TreeNode *root = NULL;
TreeNode* createNode(char *name, char *phone, char *email) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    strcpy(newNode->data.name, name);
    strcpy(newNode->data.phone, phone);
    strcpy(newNode->data.email, email);
    newNode->left = newNode->right = NULL;
    return newNode;
}
void insert(TreeNode **root, TreeNode *newNode) {
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    if (strcmp(newNode->data.name, (*root)->data.name) < 0) {
        insert(&((*root)->left), newNode);
    } else {
        insert(&((*root)->right), newNode);
    }
}
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
    TreeNode *newNode = createNode(name, phone, email);
    insert(&root, newNode);
    printf("Them thanh cong\n");
}
void displayByInorder(TreeNode *node) {
    if (node == NULL) return;
    displayByInorder(node->left);
    printf("Tên: %s\nSĐT: %s\nEmail: %s\n\n",
           node->data.name, node->data.phone, node->data.email);
    displayByInorder(node->right);
}
void displayContacs() {
    printf("Danh sach danh ba\n");
    if (root == NULL) {
        printf("Danh ba rong\n");
        return;
    }
    displayByInorder(root);
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
        getchar();
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