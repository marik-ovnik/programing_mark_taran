
#include <stdio.h>
#include <string.h> 
#define N 24
#define MIN_PRESS 3

int main(void) {
    int raw[N] = {
        0, 0, 1, 0, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 0, 0, 1,
        0, 1, 1, 1, 1, 1, 1, 0
    };
for (int i=0; i<N;i++){
    printf("%d ", raw[i]);
}
printf("\n");
    int filtered[N] = {0};
    int presses = 0;

    int i = 0;

    while (i < N) {
        if (raw[i] == 1) {
            int start = i;
            while (i < N && raw[i] == 1) {
                i++;
            }

            int duration = i - start;
            if (duration >= 3) {
                presses++;

                for (int j = start; j < i; j++) {
                    filtered[j] = 1;
                }
            }
        } else {
            i++;
        }
    }


    for (int j = 0; j < N; j++) {
        printf("%d ", filtered[j]);
    }
printf("\n");
    printf("Количество нажатий: %d\n", presses);

    return 0;
}
