#include <iostream>
#include <cstring>

using namespace std;

bool is_sub(int str1[], int str2[], int m, int n){
    if(m == 0){
        return true;
    }
    
    if(n == 0){
        return false;
    }
    
    if(str1[m-1] == str2[n-1]){
        return is_sub(str1, str2, m-1, n-1);
    }
    
    return is_sub(str1, str2, m, n-1);
}

int main(){
    int N;
    int M;
    
    cin >> N >> M;
    
    int str1[N];
    int str2[M];
    
    for(int i = 0; i < N; i++){
        cin >> str1[i];
    }
    
    for(int i = 0; i < M; i++){
        cin >> str2[i];
    }
    
    if(is_sub(str2, str1, M, N)){
        cout << "yes";
    }else{
        cout << "no";
    }
    
    return 0;
}