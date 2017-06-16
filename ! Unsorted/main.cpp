#include <iostream>
#include <cctype>
#include <stdio.h>
using namespace std;

#include <vector>
#include <string.h>

int foo(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;

    return 1;
}

#include <stdlib.h>

#define MAX_N 8
int per[MAX_N];
int cnt = 0;

void print(int n){
    cnt++;
}
int check(int p, int n){
    for(int i = 0; i < p; i++){
        if(per[i]== per[p])
            return 0;
        if(abs(i-p) == abs(per[i] - per[p]))
            return 0;
    }

    return 1;
}

void gen(int i, int n){
    if(i == n){
        print(n);
        return;

    }

    for(int j = 0; j <n; j++){
        per[i] = j;
        if(check(i, n))
            gen(i+1,n);
    }
}
int main(){
    int value =1;
    for(int i = 126; i < 625; i++)
        value = (value*i)%125;
    printf("%d",value);
    





//     int a[11];

//     for(int i =0; i < 12; i++){
//         a[i] = i;
//     }

//     for(int i =0; i <= 10; i++){
//         for(int j = 0; j < 4; j++){
//             a[i] += 1;

//         }
//         for(int j = 8; j < 12; j++){
//             a[i] += 1;

//         }
//         for(int j = 2; j < 11; j++){
//             a[i] += 2;

//         }
//         for(int j = 5; j < 8; j++){
//             a[i] += -1;

//         }
        
//     }

//     int count;

//     count = 0;
//     for(int i =0; i < 12; i++){
//         cout << a[i] << " ";
//     }
//     cout << count << endl;

//     count = 0;
//     for(int i =3; i < 4; i++){
//         cout << a[i] << " ";
//     }
// cout << count << endl;
    
//     count = 0;
//     for(int i =4; i < 5; i++){
//         cout << a[i] << " ";
//     }
// cout << count << endl;
    
//     count = 0;
//     for(int i =5; i < 8; i++){
//         cout << a[i] << " ";
//     }
// cout << count << endl;


    return 0;
}