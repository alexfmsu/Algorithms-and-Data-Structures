#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int d = 8;

    int a[d];

    int tmp;

    for(int i = 0; i < d; i++){
        cin >> tmp;

        a[i%d] = tmp;
    }

    int mx = 0;
    int m = 0;

    int i = d;
    
    do{
        cin >> tmp;

        if(a[i%d] > mx){
            mx = a[i % d];
        }
        
        if(tmp * mx > m)
            m = tmp * mx;

        a[i % d] = tmp;

        i++;
    }while(tmp >= 0);

    cout << m << endl;

    // vector<int> x;

    // int tmp;
    // do{
    //     cin >> tmp;

    //     x.push_back(tmp);
    // }while(tmp > 0);

    // if(x.size() <= 8){
    //     cout << "0" << endl;

    //     return 0;
    // }

    // long max = 0;

    // long mult;

    // for(int i = 0; i < x.size()-8; i++){
    //     int max_j = 0;
        
    //     for(int j = i+8; j < x.size(); j++){
    //         max_j = std::max(max_j, x[j]);        
    //     }

    //     mult = x[i]*max_j;
            
    //     if(mult > max)
    //         max = mult;
    // }
    // // for(int i = 0; i < x.size()-1; i++){
    // //     for(int j = i+1; j < x.size(); j++){
    // //         if(abs(i - j) < 8){
    // //         // if(abs(x[i] - x[j]) < 8){
    // //             continue;
    // //         }

    // //         mult = x[i]*x[j];
    // //         if(mult > max)
    // //             max = mult;
    // //     }
    // // }

    // cout << max << endl;

    return 0;
}