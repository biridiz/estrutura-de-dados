#include <stdio.h>
#include <stdlib.h>

typedef int Value;

typedef struct node {
    Value value;    
    struct node *left, *rigth;
} Node;


Node *insertTree(Node *root, int value) {
    Node *new;

    if (root == NULL) {
        new = malloc(sizeof(Node));
        new->value = value;
        new->rigth = NULL;
        new->left = NULL;
        return new;
    }
    else {
        if (root->value >= value)
            root->left = insertTree(root->left, value);
        else
            root->rigth = insertTree(root->rigth, value);
        
        return root;
    }
}

void printPreOrder(Node *root) {
    if (root == NULL)
        return;
    else {
        printf("|%d|", root->value);
        printPreOrder(root->left);
        printPreOrder(root->rigth);
    }
}

void printInOrder(Node *root) {
    if (root == NULL)
        return;
    else {
        printInOrder(root->left);
        printf("|%d|", root->value);
        printInOrder(root->rigth);
    }
}

void printPosOrder(Node *root) {
    if (root == NULL)
        return;
    else {
        printPosOrder(root->left);
        printPosOrder(root->rigth);
        printf("|%d|", root->value);
    }
}

int heightTree(Node *root) {
    int heigth, left, right;

    if (root == NULL)
        return 0;

    left = heightTree(root->left);
    right = heightTree(root->rigth);

    if (left >= right)
        heigth = left;
    else
        heigth = right;
    
    return heigth + 1;
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
    int i, n, op, value;
    Node *root;

    scanf("%d%*c", &n);

    if (n >= 2) {
        scanf("%d%*c", &op);
        if (op == 1) {
            root = NULL;

            for (i=0; i<(n-2); i++) {
                scanf("%d ", &op);
                if (op == 2) {
                    scanf("%d%*c", &value);
                    root = insertTree(root, value);
                }
                if (op == 3) {
                    printPreOrder(root);
                    printf("\n");
                }
                if (op == 4) {
                    printInOrder(root);
                    printf("\n");
                }
                if (op == 5) {
                    printPosOrder(root);
                    printf("\n");
                }
            }

            scanf("%d", &op);
            if (op == 6) {
                printf("Altura: %d\n", heightTree(root));
                freeTree(root);
                printf("\n");
            }
        }
    }

    return 0;
}

