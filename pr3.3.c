#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int main(){
    srand((unsigned int)time(NULL));
float ar[N];
for (int i =0; i<N; i++){
    ar[i] = (rand() %65534)-32767;
}
float ar2[N];
for (int i =0; i<N; i++){
    ar2[i] = (rand() %65534)-32767;
}
for (int i =0; i<N; i++){
    printf("ar[%d]=%f + j * (%f) \n", i, ar[i], ar2[i]);
}
float sum = 0;
for (int i =0; i<N; i++){
    sum+=((ar[i]*ar[i])+(ar2[i]*ar2[i]));
}
printf("sum is %f \n", sum);
int max = 0;
for (int i =0; i<N; i++){
    if (ar[i]>ar[max]) max = i;
}
printf("max %f,%f \n", ar[max], ar2[max]);
}