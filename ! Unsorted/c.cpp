#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main(){
    int n;

    cin >> n;

    if(n < 2){
        cout << "0" << endl;

        exit(1);
    }

    // set<double> x;
    vector<double> xx;

    for(int i = 0; i < n; i++){
        double tmp;

        cin >> tmp;

        // x.insert(tmp);
        xx.push_back(tmp);
    }

    sort(xx.begin(), xx.end());

    int count = 0;

    int i = 0;

    while(i < n){
        // double r = *std::next(x.begin(), i) + 1;
        double r = xx[i] + 1;
        
        count++;
        
        i++;

        while(i < n && xx[i] <= r){
            i++;
        }
    }

    cout << count << endl;

    return 0;
}