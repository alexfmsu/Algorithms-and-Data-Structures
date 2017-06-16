#include <iostream>

using namespace std;

int main(){    
    int N;
    int M;

    cin >> N >> M;
    
    int jumps[N+1];
    
    for(int i = 0; i < N+1; i++){
        jumps[i] = 0;
    }

    jumps[0] = 1;
    
    for(int i = 0; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i + j > N){
                break;
            }

            jumps[i+j] += jumps[i];
        }
    }
    
    cout << jumps[N];
    
    return 0;
}
