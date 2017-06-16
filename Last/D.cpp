#include <iostream>

using namespace std;

#define MAX_MINDIFF 100*100*100

int* get_binary(int x, int* x_bin){
    int i = 0;
    
    while(x != 0){
        x_bin[i++] = x%2;
        
        x = x/2;
    }
    
    return x_bin;
}
        
int main() {
    int N;
    
    cin >> N;
    
    int x[24];
    
    int* x_bin = new int[50];
    
    for(int i = 1; i <= N; i++){
        cin >> x[i];
    }
    
    int weight_1, weight_2;
    
    int min_diff = MAX_MINDIFF;
    
    int max = 1 << N;

    for(int i = 1; i <= max; i++){
        x_bin = get_binary(i, x_bin);
        
        weight_1 = weight_2 = 0;
        
        for(int j = 1; j <= N; j++){
            (x_bin[j]==1) ? (weight_1 += x[j]) : (weight_2 += x[j]);
        }
        
        min_diff = std::min(min_diff, abs(weight_1 - weight_2));
    }
    
    cout << min_diff << endl;
    
    return 0;
}