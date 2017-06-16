#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector< set<int> > v;
    
    set<int> x;

    int tmp;
    
    while(cin >> tmp){
        
        if(tmp == 0){
            v.push_back(x);

            x.clear();
        }else if(tmp == -1){
            v.push_back(x);

            break;            
        }else{
            x.insert(tmp);
        }
    }

    set<int> a = v[0];

    set<int> s;

    // for(auto i = a.begin(); i != a.end(); i++){
    //     cout << *i << " ";
    // }

    // cout << endl;

    // for(auto i = v[1].begin(); i != v[1].end(); i++){
    //     cout << *i << " ";
    // }

    for(int i = 1; i < v.size(); i++){
        std::set_symmetric_difference(a.begin(), a.end(), v[i].begin(), v[i].end(), std::inserter(s, s.begin()));
        
        a = s;

        s.clear();
    }

    if(a.empty()){
        cout << "0" << endl;
    }else{
        for(auto i = a.begin(); i != a.end(); i++){
            cout << *i << " ";
        }

        cout << endl;
    }
    // set_difference(begin(v[0]), end(v[0]),
    //                begin(v[1]), end(v[1]),
    //                inserter(a, begin(a)));

    return 0;
}