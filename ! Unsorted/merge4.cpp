#include <iostream>
#include <vector>

typedef std::vector<int> v;

using namespace std;

void sum_x1(int &n1, v const &x, bool &odd, int &sum){
    if(odd){
        sum += x[n1];
        sum %= 1000000000;
    }
    
    ++n1;
    
    odd = !odd;
}

void sum_x2(int &n2, int &x2, bool &odd, int n, int &sum){
    if(odd){
        sum += x2;
        sum %= 1000000000;
    }
    
    if(n2 < n){
        cin >> x2;
    }
    
    ++n2;
    
    odd = !odd;
}

int main(){
    int n;

    cin >> n;
    
    v x(n);
    
    for(auto &x1: x){
        cin >> x1;
    }
 
    bool odd = true;
    
    int n1 = 0, n2 = 0;
    
    int sum = 0;
    
    int x2;
    
    cin >> x2;
    
    ++n2;
    
    do{
        if(n1 < n && (n2 > n || x[n1] <= x2)){
            sum_x1(n1, x, odd, sum);
        }
        
        if(n2 <= n && (n1 >= n || x2 <= x[n1])){
            sum_x2(n2, x2, odd, n, sum);
        }
    }

    while(n1 < n || n2  <=  n);
    
    cout << sum << endl;

    return 0;
}