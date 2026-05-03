#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    float time;
};

int cmp(const void *a, const void *b) {
    return ((struct Car*)b)->position - ((struct Car*)a)->position;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int pos[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].position = pos[i];
        cars[i].time = (float)(target - pos[i]) / speed[i];
    }

    qsort(cars, n, sizeof(struct Car), cmp);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}