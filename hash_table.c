#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int value;
    struct item *next;
} Item;

typedef struct {
    Item *top;
} ItemHash;

int hash_function(int key, int size) {
    return key%size;
}

void printCollisions(Item *item) {
    if (item == NULL) 
        return;
    printCollisions(item->next);
    printf("%d -> ", item->value);
}


int main() {
    int i, j, n, positionHash, sizeTable, qntdKeys;

    scanf("%d%*c", &n);

    for (i=0; i<n; i++) {
        scanf("%d %d%*c", &sizeTable, &qntdKeys);
        
        Item *item;
        ItemHash hashTable[sizeTable];

        for (j=0; j<sizeTable; j++) {
            hashTable[j].top = NULL;
        }

        for (j=0; j<qntdKeys; j++) {
            item = malloc(sizeof(Item));

            scanf("%d", &item->value);
            item->next = NULL;

            positionHash = hash_function(item->value, sizeTable);

            if (hashTable[positionHash].top == NULL)
                hashTable[positionHash].top = item;
            else {
                item->next = hashTable[positionHash].top;
                hashTable[positionHash].top = item;
            }
        }

        for (j=0; j<sizeTable; j++) {
            if (hashTable[j].top == NULL)
                printf("%d -> \\\n", j);
            else {
                item = hashTable[j].top;
                printf("%d -> ", j);
                
                if (item->next != NULL)
                    printCollisions(item);
                else
                    printf("%d -> ", item->value);

                printf("\\\n");
            }
        }
        printf("\n");
    }

    return 0;
}