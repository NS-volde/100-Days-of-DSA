#include <stdio.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (freq[idx] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        freq[idx]++;
    }

    // If no repeated character
    printf("-1\n");

    return 0;
}