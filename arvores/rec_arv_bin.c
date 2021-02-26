#include <stdio.h>
#include <stdlib.h>

typedef char Value;

typedef struct node {
    Value value;
    char c_left, c_rigth;
    struct node *left, *rigth;
} Node;


void scanNode(char *node) {
    scanf("%c", &node[0]);
    scanf("%c", &node[1]);
    scanf("%c", &node[2]);
}

Node *insertTree() {
    Node *root;
    char node[3];

    root = NULL;

    scanNode(node);

    if (root == NULL) {
        root = malloc(sizeof(Node));
        root->value = node[0];
        root->c_left = node[1];
        root->c_rigth = node[2];
        root->rigth = NULL;
        root->left = NULL;
    }

    if (root->c_left == '1'){
        root->left = insertTree();
    }

    if (root->c_rigth == '1'){
        root->rigth = insertTree();
    }

    return root;
}

void printInOrder(Node *root) {
    if (root == NULL)
        return;
    else {
        printInOrder(root->left);
        printf("%c", root->value);
        printInOrder(root->rigth);
    }
}

void printPosOrder(Node *root) {
    if (root == NULL)
        return;
    else {
        printPosOrder(root->left);
        printPosOrder(root->rigth);
        printf("%c", root->value);
    }
}

void freeTree(Node *root) {
    if (root == NULL)
        return;
    else {
        freeTree(root->left);
        freeTree(root->rigth);
    }
    root = NULL;
    printf("0");
}


int main() {
    int n;
    Node *root = NULL;

    scanf("%d", &n);
    scanf("\n");

    root = insertTree();
    
    printInOrder(root);
    printf("\n");

    printPosOrder(root);
    printf("\n");

    freeTree(root);
    printf("\n");
    
    return 0;
}

