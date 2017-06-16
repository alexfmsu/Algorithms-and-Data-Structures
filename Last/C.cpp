#include <iostream>
#include <vector>

using namespace std;

#define INF 1000 * 1000 * 1000

typedef vector<vector<int> > IntGraph;

void run_dist(IntGraph &g, IntGraph &g1, int N, int i, int j){
    for(int k = 0; k < N; k++){
        if(g[i][k] && g[k][j]){
            int i_j = g[i][k] + g[k][j];
            
            if(g1[i][j] == 0 || i_j < g1[i][j]){
                g1[i][j] = i_j;
            }
        }
    }
}

void run(IntGraph &g, IntGraph &g1, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                run_dist(g, g1, N, i, j);
            }
        }
    }
}



int main(){
    int N;
    
    cin >> N;
    
    IntGraph g(N, vector<int>(N)), g1;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> g[i][j];
        }
    }
    
    g1 = g;
    
    for(int i = 1; i < N; i++){
        run(g, g1, N);
        
        g = g1;
    }
    
    int max = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            max = std::max(max, g[i][j]);
        }
    }
    
    cout << max << endl;
    
    return 0;
}
