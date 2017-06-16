
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace ::std;

int gcd (int a, int b){
    if (b == 0) {
        return a;
    }
    else {
        return gcd (b, a % b);
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int sum = 0;
    int f = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (gcd(arr[i], arr[i + 1]) > 1) {
            sum++;
        }
    }
    
    cout << sum << endl;
    
    
    return 0;
}