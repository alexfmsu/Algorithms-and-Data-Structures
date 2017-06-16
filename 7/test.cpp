

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace ::std;

vector<vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;
map<int, pair<int, int> > m;

int num = 0;

void dfs1(int v) {
    used[v] = true;
    
    for (int i = 0; i < g[v].size(); ++i) {  
        if ((g[v][i] > 0) && !used[i]){
            dfs1(i);
        }
    }
    
    order.push_back(v); 
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < gr[v].size(); ++i) {
        if ((gr[v][i] > 0) && !used[i]) {
            dfs2(i);
        }
    }
}



int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    g.resize(N, vector<int>(N));
    gr.resize(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        g[i].assign(N, 0);
        gr[i].assign(N, 0);
    }
    
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1 - 1][v2 - 1] = 1;
        gr[v2 - 1][v1 - 1] = 1;
        m[v1].first++;
        m[v2].second++;
    }

    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    
    int count = 0;
    
    used.assign(N, false);
    for (int i = 0; i < N; ++i) {
        int v = order[N - 1 - i];
        if (!used[v]) {
            dfs2(v);
            count++;
            component.clear();
        }
    }
    
    

    int f = 1;
    map<int, pair<int, int> >::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
    
        if ((*it).second.first != (*it).second.second || (*it).second.first < 1 || (*it).second.second < 1) {
            f = 0;
    
        }
    }
    
    if (f == 0 || count != 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }


    
    
    
    return 0;
}