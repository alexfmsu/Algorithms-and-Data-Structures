#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long n;

    scanf("%lld", &n);
    
    if(n <= 0 || n > 1e18){
        cout << "0" << endl;

        return 0;
    }

    long long count = 0;
    
    long long x = 0;
    long long y;
    
    long long x2 = 0;

    for(long x = 0; x <= n; x++){
        x2 = x*x;
        
        if(x2 > n)
            continue;
        
        for(long y = 0; y <= n; y++){
            if(x2 + y*y <= n){
                // cout << "(" << x << "," << y << ")" << endl;
                count++;
            }
        }    
    }

    printf("%lld\n", count);
    
    return 0;
}

// if(N <= 1){
//         cout << "0" << endl;

//         return 1;
//     }

//     int count = 0;

//     long long x2;

//     for(long x = 0; x <= N; x++){
//         x2 = x*x;
        
//         if(x2 > N)
//             continue;

//         for(long y = 0; y <= N; y++){
//             if(x2 + y*y <= N){
//                 // cout << "(" << x << "," << y << ")" << endl;
//                 count++;
//             }
//         }    
//     }

//     cout << count << endl;