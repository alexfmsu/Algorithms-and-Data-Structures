#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int N, M;

    cin >> N >> M;

    int** x;

    x = new int*[N];
    
    int max = 0;

    for(int i = 0; i < N; i++){
        x[i] = new int[M];

        for(int j = 0; j < M; j++){
            cin >> x[i][j]; 
        }
    }
    
    for(int i = 0; i < N; i++){
        std::sort(x[i], x[i] + M);
    }
    
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            std::vector<int> v(M*2);

            std::vector<int>::iterator it;
            it=std::set_intersection (x[i], x[i]+M, x[j], x[j]+M, v.begin());
            
            max = std::max(max, (int)(it-v.begin()));
        }
    }
    
    cout << max << endl;
    
    return 0;
}