#include <stdio.h>
void pop(unsigned int a){
    int z = 0;
    int o = 0;
    if (a == 0)
    {
        z = 1;
    }
    else
    {
while (a != 0)
        {
            if ((a & 1)==1)
                o++;
            else
                z++;

            a = a>>1;
}
    }
printf("%d нули %d еденицы", z+1, o);
}

int main()
{
    unsigned int a;
    int z = 0;
    int o = 0;

    printf("Введите неотрицательное число a: ");
    scanf("%u", &a);

    
        pop(a);
        
    

    

    return 0;
}