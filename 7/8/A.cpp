#include <iostream>
#include <vector>

using namespace std;


long long int get_tickets(int n, int m, int l, int mod, vector<vector<long long int> > &x){
    if(l < 0){
        return 0;
    }
    
    if(n == 1){
        return l + 1 <= m;
    }

    long long int sum = x[n][l];
    
    if(sum < 0){
        sum = 0;

        for(int i = 0; i + 1 <= m; i++){
            sum += get_tickets(n - 1, m, l - i, mod, x);
            
            sum %= mod;
        }

        x[n][l] = sum;
    }

    return sum;
}



int main(int argc, char** argv){
    int N, M, mod;

    cin >> N >> M >> mod;
    
    int l = (M - 1) * N / 2;
    
    vector<vector<long long int> > x(N + 2, vector<long long int>(l + 2));

    
    for (int i = 0; i < N + 2; i++){
        for (int j = 0; j < l + 2; j++){
            x[i][j] = -1;
        }
    }
    
    long long int happy_tickets = get_tickets(N, M, l, mod, x);
    
    cout << happy_tickets << endl;
    
    return 0;
}