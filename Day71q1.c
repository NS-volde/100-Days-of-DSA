#include <stdio.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &q);   // number of operations

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        int h = key % m;

        // INSERT
        if (op[0] == 'I') {
            int i = 0;
            while (i < m) {
                int idx = (h + i*i) % m;

                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        }

        // SEARCH
        else {
            int i = 0;
            int found = 0;

            while (i < m) {
                int idx = (h + i*i) % m;

                if (table[idx] == EMPTY) {
                    break;
                }

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}