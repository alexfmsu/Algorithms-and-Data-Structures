#include <iostream>
#include <stdio.h>

using namespace std;

int Sqrt(int x) {
    unsigned long l = 0, r = x;
    
    while (l <= r) {
        unsigned long mid = l + (r - l) / 2;
        unsigned long midmid = mid * mid;
            
        if ((midmid <= x) && (x < (mid + 1) * (mid + 1))) return mid;            
        if (midmid > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main() {
    long long n;

    scanf("%lld", &n);

    if(n <= 0){
        cout << "0" << endl;

        return 0;
    }

    long long x = 0, y; 

    long long count = 0;
    long long count_x;
    
    while(x <= Sqrt(n)){ 
        count_x = 0; 
        
        y = 0;

        while(x*x + y*y < n){ 
            y++; 

            count_x++;
        }
        
        x++; 

        count += count_x; 
    } 

    printf("%lld\n", count);

    return 0;
}