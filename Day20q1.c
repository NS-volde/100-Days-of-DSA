/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefixSum = 0;

    // Simple hash array (range assumption)
    int freq[20001] = {0};  // supports sum range [-10000, 10000]
    int offset = 10000;     // shift for negative index

    freq[offset] = 1; // prefix sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If prefixSum seen before → add its frequency
        count += freq[prefixSum + offset];

        // Increase frequency
        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    return 0;
}