#include <stdio.h>
 
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
 
int main(void) {
    int a[] = {4, 2, 0};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    sort(a, n);
    return 0;
}

