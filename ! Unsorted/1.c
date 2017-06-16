#include <stdio.h>
#include <string.h>

#define min(a, b) a<b ? a:b;

int main(void){
    int n = 11;

    int a[] = {4, -7, 0, 0, -4, -2, -4, 6, 8, -1, 2};

    int min = a[0]&a[0];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            min = min(a[i]&a[j],min);

    printf("%d",min);    



    return 0;
}