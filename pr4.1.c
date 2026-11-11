#include <stdio.h>
#include <string.h>

long long det(int N, int mat[N][N]) {
    if (N == 2) {
        return (long long)mat[0][0] * mat[1][1]
             - (long long)mat[0][1] * mat[1][0];
    }

    if (N == 3) {
        return (long long)mat[0][0] * ((long long)mat[1][1] * mat[2][2] - (long long)mat[1][2] * mat[2][1])
             - (long long)mat[0][1] * ((long long)mat[1][0] * mat[2][2] - (long long)mat[1][2] * mat[2][0])
             + (long long)mat[0][2] * ((long long)mat[1][0] * mat[2][1] - (long long)mat[1][1] * mat[2][0]);
    }

    return 0;
}

int main() {
    int N;
    char op[3]={'x','y','z'};
    printf("введи размер строны квадратной матрицы \n");
    scanf("%d", &N);

    if (N < 2 || N > 3) {
        printf("2<=N<=3\n");
        return 0;
    }

    int mat[N][N];
    int ar[N];
printf("введи матрицу %d на %d \n", N,N);
    if (N == 3) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d", &mat[i][0], &mat[i][1], &mat[i][2], &ar[i]);
        }
    }

    if (N == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &mat[i][0], &mat[i][1], &ar[i]);
        }
    }

    long long D = det(N, mat);

    if (D == 0) {
        printf("определитель 0\n");
        return 0;
    }
    for (int k = 0; k < N; k++) {
        int temp[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = mat[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            temp[i][k] = ar[i];
        }

        long long Dk = det(N, temp);

        double x = (double)Dk / D;

        printf("%c = %f\n", op[k], x);
    }

    return 0;
}