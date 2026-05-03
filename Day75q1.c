#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // simple hash using arrays
    int sum[MAX * 2];     // store prefix sums
    int index[MAX * 2];   // store first index
    int size = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum becomes 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        int found = 0;

        // check if prefixSum seen before
        for (int j = 0; j < size; j++) {
            if (sum[j] == prefixSum) {
                int len = i - index[j];
                if (len > maxLen) {
                    maxLen = len;
                }
                found = 1;
                break;
            }
        }

        // store if not found
        if (!found) {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}