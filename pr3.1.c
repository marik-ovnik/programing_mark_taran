#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int sum = 0;
     srand((unsigned int)time(NULL));
    int ar[12];
    for(int i =0 ; i<12; i++){
        ar[i]= rand() % 10;
    }
    for(int i =0 ; i<12; i++){
        printf("ar[%d]= %d \n", i, ar[i]);
        sum+=ar[i];
    }
printf("sum=%d \n", sum);
printf("sred=%f \n", sum/12.0);
int min = 0;
int max = 0;
for(int i=0; i<12; i++){
    if (ar[i]>ar[max]){
        max = i;
    }
    else if (ar[i]<ar[min]){
        min = i;
    }
}
printf("min %d, max %d \n", ar[min], ar[max]);
}