#include <iostream>
#include <vector>

using namespace std;

vector<vector <char> > cell;
vector<pair<int, int> > step;

void run(int r, int m, int n){
    bool flag = true;
    bool checked;
    
    while(cell[0][0] != 'x' && cell[0][0] != 'o'){
        if(flag){
            for(int x = 0; x <= r; x++){
                for(int y = 0; y <= r; y++){
                    for(int k = 0; k < m; k++){
                        int _x = x + step[k].first;
                        int _y = y + step[k].second;

                        if(_x <= n && _y <= n) {
                            if(cell[x][y] != 'o' && cell[_x][_y] == 'o'){
                                cell[x][y] = 'x';
                            }
                        }else{
                            cell[x][y] = 'x';
                        }
                    }
                }
            }
        }else{
            for(int x = 0; x <= r; x++){
                for(int y = 0; y <= r; y++){
                    checked = true;

                    for(int k = 0; checked && k < m; k++){
                        int _x = x + step[k].first;
                        int _y = y + step[k].second;

                        if(_x <= n && _y <= n){
                            if(cell[x][y] == 'x' || cell[_x][_y] != 'x'){
                                checked = false;
                            }
                        }
                    }
                    
                    if(checked){
                        cell[x][y] = 'o';
                    }
                }
            }
        }
        
        flag = !flag;
    }
}

int main(int argc, char** argv){
    int n, r, m;
    
    cin >> n >> r >> m;
    
    if(r == 0){
        cout << 1;
    }
    
    step.resize(m);
    
    for(int i = 0; i < m; i++){
        cin >> step[i].first >> step[i].second;
    }
    
    int len = n+1;
    cell.resize(len, vector<char>(len));
    
    for(int x = 0; x < n; x++){
        for(int y = n; (y >= 0) && (x*x + y*y >= r*r); y--){
            cell[x][y] = 'o';
        }
    }
    
    run(r, m, n);
    
    if(cell[0][0] == 'x'){
        cout << 1;
    }else{
        cout << 2;
    }
    
    return 0;
}