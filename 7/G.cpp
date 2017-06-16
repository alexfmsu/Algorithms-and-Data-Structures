
#include <stdio.h>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace ::std;

enum{
    INF = 2000000000
};

vector<vector<int> > g;
vector<int> d, p;
vector<char> u;
vector<int> comp;


void dijkstra(int s, int N) {
    for (int i = 0; i < N; ++i) {
        int v = -1;
        for (int j = 0; j < N; ++j) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INF) {
            break;
        }
        u[v] = true;
        
        for(int j = 0; j < g[v].size(); ++j) {
            int to = j;
            int len = g[v][j];
            if (d[v] + len < d[to]) {   //релаксация для кажого соседа
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}


void dfs(int v) {
    u[v] = true;
    comp.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int to = i;
        if (!u[to]) {
            dfs(to);
        }
    }
}

void find_comps(int N) {
    for (int i = 0; i < N; ++i) {
        u[i] = false;
    }
    for (int i = 0; i < N; ++i) {
        if (!u[i]) {
            comp.clear();
            dfs(i);
            
            cout << "Component:";
            for (int j = 0; j < comp.size(); ++j) {
                cout << ' ' << comp[j];
            }
            cout << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    g.resize(N, vector<int>(N));
    d.assign(N, INF);
    p.resize(N);
    u.assign(N, false);
    
    int s = 0;          //стартовая вершина
    d[s] = 0;           //расстояние до стартовой вершины - 0
    
    
    //считываем матрицу смежности орграфа
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0) {
                g[i][j] = INF;
            }
        }
    }
    
    dijkstra(s, N);

    cout << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
 
    
    // find_comps(N);

}