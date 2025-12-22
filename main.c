#include <stdio.h>
#include <stdlib.h>

int tsize, hash[100], count = 0;


int Cal_Hash(int key) {
    return key % tsize;
}


int Cal_ReHash(int index) {
    return (index + 1) % tsize;
}


void insert(int key) {
    int index;

    if (count == tsize) {
        printf("\nHash table is full");
        return;
    }

    index = Cal_Hash(key);

    while (hash[index] != -1) {
        index = Cal_ReHash(index);
    }

    hash[index] = key;
    count++;
    printf("\nKey inserted");
}

int search(int key) {
    int i, index, loc;

    index = Cal_Hash(key);

    for (i = 0; i < tsize; i++) {
        loc = (index + i) % tsize;

        if (hash[loc] == key)
            return loc;
    }
    return -1;
}


void delete(int key) {
    int loc;

    if (count == 0) {
        printf("\nHash table is empty, can't delete");
        return;
    }

    loc = search(key);

    if (loc != -1) {
        hash[loc] = -1;
        count--;
        printf("\nKey deleted");
    } else {
        printf("\nKey not found");
    }
}


void display() {
    int i;
    printf("\nElements in the hash table:\n");

    for (i = 0; i < tsize; i++) {
        printf("Index %d : %d\n", i, hash[i]);
    }
}


int main() {
    int i, key, ch, loc;

    printf("Enter the size of the hash table: ");
    scanf("%d", &tsize);

    for (i = 0; i < tsize; i++)
        hash[i] = -1;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("\nEnter key to search: ");
                scanf("%d", &key);
                loc = search(key);
                if (loc != -1)
                    printf("\nKey found at index %d", loc);
                else
                    printf("\nKey not found");
                break;

            case 3:
                printf("\nEnter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
