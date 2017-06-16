#include <iostream>
#include <algorithm>

using namespace std;

void get_max_len(int wires[], int N, int K, long long left, long long right, long long &M){
    int mid = left + (right - left) / 2;
    
    if(mid == left){
        return;
    }

    int count = 0;
    
    for(int i = 0; i < N && wires[i] >= mid; i++){
        count += wires[i] / mid;
    }
    
    if(count >= K){
        if(mid > M){
            M = mid;
        }
        
        get_max_len(wires, N, K, mid, right, M);
    }else{
        get_max_len(wires, N, K, left, mid, M);
    }
}

int main (){
    int N;
    int K;
    
    cin >> N >> K;

    long long M = 0;

    long long left = 0;
    long long right=0;
    
    int wires[N];
    
    for(int i = 0; i < N; i++){
        cin >> wires[i];

        right += wires[i];
    }
    
    std::sort(wires, wires+N);
    std::reverse(wires, wires+N);
    
    get_max_len(wires, N, K, left, right, M);
    
    cout << M;
    
    return 0;
}