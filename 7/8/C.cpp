#include <algorithm>
#include <iostream>
#include <vector>

using namespace ::std;

typedef pair<int,int> point;

bool comp(pair<int, point > a, pair<int, point > b){
    return (a.first <= b.first);
}


int main(int argc, char** argv){    
    int N;

    cin >> N;
    
    vector<pair<int, point> > g;
    
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int w;

            cin >> w;
            
            if(i < j){
                g.push_back(make_pair(w, make_pair(i, j)));
            }
        }
    }
    
    int cost = 0;

    vector<point> res;
    
    std::sort(g.begin(), g.end());
    
    vector<int> city(N);
    
    for(int i = 0; i < N; i++){
         city[i] = i;
    }
    
    int m = (int)g.size();
    
    for(int i = 0; i < m; i++){
        int a = g[i].second.first;
        int b = g[i].second.second;
        int l = g[i].first;

        if(city[a] != city[b]){
            cost += l;

            res.push_back(make_pair(a, b));
            
            int old_id = city[b],  new_id = city[a];
            
            for(int j = 0; j < N; j++){
                if (city[j] == old_id){
                    city[j] = new_id;
                }
            }
        }
    }
    
    cout << cost << endl;
    
    return 0;
}
