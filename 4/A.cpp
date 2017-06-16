#include <iostream>

using namespace std;

int main (){
    int N;
    
    cin >> N;
    
    int x;
    
    int a[N][N];
    
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    
    cin >> x;

    int i = 0;
    int j = 0;
    
    if(a[0][0] == x){
        cout << "yes";
        
        return 0;
    }else if(a[0][0] > x){
        cout << "no";
        
        return 0;
    }else if(a[N-1][N-1] < x){
        cout << "no";
        
        return 0;
    }
    
    while(j < N-1 && a[0][j+1] <= x){
        j++;
    }
    
    while(j >= 0){
        if(a[i][j] == x){
            cout << "yes";
            
            return 0;
        }
        
        if(i == N-1 || a[i+1][j] > x){
            j--;
            
            continue;
        }else if(a[i+1][j] <= x){
            i++;
            
            continue;
        }
    }
    
    cout << "no";
    
    return 0;
}