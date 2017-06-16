#include <iostream>

using namespace std;

int get_a_k(int x[], int left, int right){
    int mid = left + (right - left) / 2;
    
    if(x[mid - 1] < x[mid] && x[mid] > x[mid + 1]){
        return x[mid];
    }else{
        if(x[mid - 1] < x[mid] && x[mid] < x[mid + 1]){
            get_a_k(x, mid, right);
        }
        
        if(x[mid - 1] > x[mid] && x[mid] > x[mid + 1]){
            get_a_k(x, left, mid);
        }
    }
}

int main(){
    int N;
    
    cin >> N;
    
    int x[N];
    
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    
    cout << get_a_k(x, 0, N-1);
    
    return 0;
}