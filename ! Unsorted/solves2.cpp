#include <iostream>
#include <stdio.h>

using namespace std;

int Sqrt(int x) {
    return 1+(x-1)/2;
}

int main() {
    long long n;

    long long count = 0;
    
    long long x;
    long long x2;
    long long y;
    
    scanf("%lld", &n);

    if(n<=0){
       return 0;
    }

    x = 0;
    x2 = 0;
    
    long long delta = n - x2;    
    
    long long sq = Sqrt(n);

    
    for(x = 0; x <= sq; x++){
        long x2 = x*x;

        for(long y = 0; y <= sq; y++){
            if(x2 + y*y < n)count++;
        }
    }
    // while(x <= Sqrt(n)){
    //     y = 0;
        
    //     while(y*y < delta){
    //         y++;
    //     }

    //     x++;
        
    //     delta = n - x*x;

    //     count += y;
    // }
    
    printf("%lld\n", count);
    
    return 0;
}