#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > g,m;
vector<int> path;

int** edges;

// map<pair<int, int>, int> edges;
vector<bool> used;

int l = 0;

int roads(int start, int finish, int CN){
    l++;
    
    path.push_back(start);
    
    if(start == finish) {
        m.push_back(path);
        
        return 1;
    }
    
    int sum = 0;
    
    for(int i = 0; i < g[start].size(); i++){
        if(i != CN && g[start][i] != 0 && edges[start][i] == 0){
            edges[start][i]++;
            edges[i][start]++;
            
            sum += roads(i, finish, CN);
            edges[start][i] = 0;
            edges[i][start] = 0;
                
            path.pop_back();
        }
    }
    
    return sum;
}


int main(int argc, char** argv){
    int N, M, C, CN, CS;

    cin >> N >> M >> C;
    
    edges = new int*[N*N];
    for(int i = 0; i < N*N; i++){
        edges[i] = new int[N*N];

        for(int j = 0; j < N*N; j++){
            edges[i][j] = 0;
        }
    }
    
    g.resize(N, vector<int>(N));
    used.assign(N, false);
    
    for (int i = 0; i < N; i++){
        g[i].assign(N, 0);
    }

    for(int i = 0; i < M; i++){
        int v1, v2, c;

        cin >> v1 >> v2 >> c;
        
        g[v1 - 1][v2 - 1] = g[v2 - 1][v1 - 1] = c + 1;
    }
    
    cin >> CN >> CS;
    
    int res = roads(CN - 1, CS - 1, CN - 1);
    
    int num = 0;
    
    vector<int> ans;
    vector<int> comp(C + 1);
    
    for(int i = 0; i < m.size(); i++){
        comp.assign(C + 1, 0);

        for(int j = 0; j < m[i].size() - 1; j++){
            int ind = g[m[i][j]][m[i][j + 1]] - 1;
            comp[ind]++;
        }
        
        for(int k = 1; k < comp.size(); k++){

            if(comp[k] == 0){
                num++;
                ans.push_back(k);
            }
        }
    }
    
    cout << num << endl;
    
    sort(ans.begin(), ans.end());
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}