#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > g1, g2;

vector<bool> isUsed;

vector<int> order, component;

void notUsedHandle(int v){
    isUsed[v] = true;
    
    for(int i = 0; i < g1[v].size(); i++){
        if(!isUsed[i] && g1[v][i] > 0){
            notUsedHandle(i);
        }
    }
    
    order.push_back(v);
}

void usedHandle(int v){
    isUsed[v] = true;
    
    component.push_back(v);
    
    for(int i = 0; i < g2[v].size(); i++){
        if(!isUsed[i] && g2[v][i] > 0){
            usedHandle(i);
        }
    }
}



int main(int argc, char** argv){
    int N;
    
    cin >> N;
    
    g1.resize(N, vector<int>(N));
    g2.resize(N, vector<int>(N));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> g1[i][j];

            g2[j][i] = g1[i][j];
        }
    }
    
    isUsed.assign(N, false);
    
    for(int i = 0; i < N; i++){
        if(!isUsed[i]){
            notUsedHandle(i);
        }
    }
    
    int count = 0;
    
    isUsed.assign(N, false);
    
    for(int i = 0; i < N; i++){
        int v = order[N - i - 1];
        
        if(!isUsed[v]) {
            usedHandle(v);
                
            count++;
            component.clear();
        }
    }
    
    cout << count << endl;
    
    return 0;
}