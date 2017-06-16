#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef std::pair<double, double> point;

int main(){
    int n;

    cin >> n;

    if(n < 3){
        cout << "0" << endl;
        
        return 0;
    }

    double x, y;

    point p[n];

    for(int i = 0; i < n; i++){
        cin >> x >> y;

        p[i] = make_pair(x, y);
    }

    vector<point> left_x, right_x;
    vector<point> left_y, right_y;

    for(int i = 0; i < n; i++){
        if(p[i].second == 0){
            if(p[i].first < 0){
                left_x.push_back(p[i]);
            }else if(p[i].first > 0){
                right_x.push_back(p[i]);
            }
        }else{
            if(p[i].first < 0){
                left_y.push_back(p[i]);
            }else if(p[i].first > 0){
                right_y.push_back(p[i]);
            }
        }
    }

    double max_ab_l = 0;
    double max_ab_r = 0;

    if(left_x.size() > 1){
        for(int i = 0; i < left_x.size()-1; i++){
            for(int j = i+1; j < left_x.size(); j++){
                double ab = abs(left_x[i].first - left_x[j].first);
                
                if(max_ab_l == 0 || ab > max_ab_l){
                    max_ab_l = ab;
                }
            }
        }
    }

    if(right_x.size() > 1){
        for(int i = 0; i < right_x.size()-1; i++){
            for(int j = i+1; j < right_x.size(); j++){
                double ab = abs(right_x[i].first - right_x[j].first);
            
                if(max_ab_r == 0 || ab > max_ab_r){
                    max_ab_r = ab;
                }
            }
        }
    }
    
    double max_y_l = 0;

    if(left_y.size() != 0){
        for(int i = 0; i < left_y.size(); i++){
            if(max_y_l == 0 || abs(left_y[i].second) > max_y_l){
                max_y_l = abs(left_y[i].second);
            }
        }
    }

    double max_y_r = 0;

    if(right_y.size() != 0){
        for(int i = 0; i < right_y.size(); i++){
            if(max_y_r == 0 || abs(right_y[i].second) > max_y_r){
                max_y_r = abs(right_y[i].second);
            }
        }
    }

    double max_l = 0.5 * max_ab_l * max_y_l;
    double max_r = 0.5 * max_ab_r * max_y_r;

    double max_sq = std::max(max_l, max_r);
    
    if(max_sq > 0){
        printf("%.4f", max_sq);
    }else{
        cout << "0";
    }
    
    return 0;
}