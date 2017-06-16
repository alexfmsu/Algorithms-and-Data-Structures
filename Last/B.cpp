#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > IntGraph;

IntGraph init_graph(int N){
    IntGraph  g(N + 1, vector<int>(N + 1));
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            g[i][j] = 0;
        }
    }

    return g;
}

void run(IntGraph &g, int N, int k, int flag[]){
    if(flag[k] != 0){
        return;
    }

    flag[k] = 1;
    
    for(int i = 1; i <=N; i++){
        if(g[k][i]){
            run(g, N, i, flag);
        }
    }
}

int main(){
    int N, M;
    
    cin >> N >> M;
    
    int  P, Q;
    
    cin >> P;
    
    IntGraph g = init_graph(N);
    
    int flag[N+1];
    
    while(P != 0){
        cin >> Q;
        
        g[P][Q] = 1;
        g[Q][P] = 1;
        
        cin >> P;
    }

    for(int i = 0; i <= N; i++){
        flag[i] = 0;
    }

    run(g, N, 1, flag);
    
    for(int i = 1; i <= N; i++){
        if(flag[i] == 0){
            cout << "No" << endl;

            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}