#include <iostream>

using namespace std;

#define MAX_N 10000
#define INF 40000

int main(){
    int N, x;

    int a[MAX_N], b[MAX_N];
    
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            if(a[i] > a[j]){
                std::swap(a[i], a[j]);
            }
        }
    }
    
    a[0] = INF;
    a[-1] = 0;

    b[0] = b[-1] = 0;
    
    for(int i = 1; i <= N; i++){
        b[i] = std::min(b[i-1], b[i-2]) + abs(a[i] - a[i-1]);
    }

    cout<<b[N]<<endl;
}
