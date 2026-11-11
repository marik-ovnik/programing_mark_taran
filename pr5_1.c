#include <stdio.h>
#include <string.h>

int main(){
char word[100];
fgets(word, sizeof(word),stdin);
int a[26];

for(int i =0; i<27;i++){
    a[i]= 0;
}
for(int i=0;i<strlen(word); i++){
    if (word[i]>96){
    a[word[i]-'a']+=1;
    }
    else if(word[i]>64){
        a[word[i]-'A']+=1;
    }

}
printf("abcdefghijklmnopqrstuvwxyz \n");
    for(int i=0; i<27; i++){
        printf("%d", a[i]);
    }
    printf("\n");
    int l1= 0;
    int l2 = 0;
    int l3 = 0;
    char c1;
    char c2;
    char c3;
    for(int i; i<27;i++){
        if (a[i]>l1){
            l1 = a[i];
            c1 = i+'a';
        }
    }
    for(int i; i<27;i++){
        if (a[i]>l2 && i+'a'!=c1){
            l2 = a[i];
            c2 = i+'a';
        }
    }
    for(int i; i<27;i++){
        if (a[i]>l3 && (i+'a' !=c1 && i+'a' != c2)){
            l3 = a[i];
            c3 = i+'a';
        }
    }
    printf("%d - %c \n %d - %c \n %d - %c", l1, c1, l2,c2,l3,c3);
    
}
