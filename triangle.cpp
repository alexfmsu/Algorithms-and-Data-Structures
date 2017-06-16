#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double square(double ab, double c){
    return ab * c / 2.0;
}

int main(){
    int n;
    cin >> n;
    
    double x, y;
    
    std::pair<double, double> A[n];

    for(int i = 0; i < n; i++){
        cin >> x >> y;

        A[i] = make_pair(x, y);
    }

    double max_sq = 0;
    
    for(int i = 0; i < n-1; i++){
        std::pair<double, double> a;

        if(A[i].second == 0){
            a = A[i];
        }else continue;

        for(int j = i+1; j < n; j++){
            std::pair<double, double> b;

            if(A[j].second == 0){
                b = A[j];
            }else continue;

            if(a.first > 0 && b.first > 0 || a.first < 0 && b.first < 0){

            }else continue;

            for(int k = 0; k < n; k++){
                if(A[k] == a || A[k] == b)
                    continue;

                std::pair<double, double> c;

                c = A[k];
                
                if(A[k].second != 0 && (a.first > 0 && c.first > 0 || a.first < 0 && c.first < 0) && (b.first > 0 && c.first > 0 || b.first < 0 && c.first < 0)){
                    double ab = abs(a.first - b.first);
                    
                    double _sq = square(ab, abs(c.second));
                    
                    if(_sq > max_sq)max_sq = _sq;
                }      
            }    
        }
    }

    if(max_sq > 0)
        printf("%.4f", max_sq);
    else
        cout << 0;
    return 0;
}