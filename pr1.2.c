#include <stdio.h>
void bites(int size, int a){
printf("Биты с четными индексами: ");

    for (int i = 0; i < size; i += 2)
    {
        printf("%u ", (a >> i) & 1);
    }

    printf("\n Биты с нечетными индексами: ");

    for (int i = 1; i < size; i += 2)
    {
        printf("%u ", (a >> i) & 1);
    }
    printf("\n");
}

int main()
{
    unsigned int a;
    int bits = 0;
    unsigned int t;

    printf("Введите число a: ");
    scanf("%u", &a);

    t = a;

    
    if (t == 0)
        bits = 1;
    else
    {
        while (t != 0)
        {
            bits++;
            t >>= 1;
        }
    }

    bites(bits,a);

    

    return 0;
}