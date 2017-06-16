#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Table{
public:
    string name;

    vector<int> a;

    int k;
};

bool pred(std::pair< string, Table* > x, std::pair< string, Table > &y){
    // return x.a[0] > y.a[0];
    return true;
}



int main(){
    int N;
    cin >> N;

    int K;
    cin >> K;

    map<string, Table> prior;

    vector<Table> T;

    int pr[K];
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;

        pr[i] = 0;
    }

    for(int i = 0; i < N; i++){ 
        Table t;
        cin >> t.name;

        for(int j = 0; j < K; j++){
            int tmp;
            cin >> tmp;

            t.a.push_back(tmp);
        }

        T.push_back(t);

        // int key = pr[i];
        prior[t.name] = t;
    }

    for(int i = 0; i < N; i++){
        cout << T[i].name << " ";

        for(int j = 0; j < K; j++){
            cout << T[i].a[j] << " ";
        }

        cout << endl;
    }

    sort(prior.begin(), prior.end(), [](std::pair<std::string, Table> elem1 ,std::pair<std::string, Table> elem2){ return elem1.first > elem2.first;});


    return 0;
} 