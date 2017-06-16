#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, vector<int> > value;

typedef map<string, value> S;

int main(){
    string s;
    cin >> s;
    
    int max_weight = 0;
    
    int len = s.length();

    S X;
    
    string str;

    for(int i = 0; i < len; i++){
        str = "" + s[i];

        X[str].first++;
        X[str].second.push_back(i);
    }
    
    for(auto _x: X){
        int weight = _x.second.first;
                        
        if(weight > max_weight){
            max_weight = weight;
        }
    }

    for(int i = 1; i < len; i++){
        S node;
        
        for(auto _x: X){
            string prefix = _x.first;
            
            vector<int>* last = &_x.second.second;
            
            int last_index;

            for(int k = last->size()-1; k >= 0; k--){
                last_index = last->at(k);

                if(last_index != len - 1){
                    int next_ind = last_index + 1;

                    char postfix = s[next_ind];
                    
                    str = prefix + postfix;

                    node[str].first++;

                    node[str].second.push_back(next_ind);
                }
            }
        }
        
        int weight = (i+1) * node.begin()->second.first;
                        
        if(weight > max_weight){
            max_weight = weight;
        }
        
        X = node;
    }

    cout << max_weight;

    return 0;
}