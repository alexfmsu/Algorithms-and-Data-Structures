#include <iostream>

using namespace std;

#define MAX_SIZE 256

int main (){    
    unsigned long N;
    unsigned long K;
    unsigned long M;
    unsigned long L;
    
    unsigned long RESULT = 0;
    
    cin >> N >> K >> M >> L;
    
    unsigned int x[N];
    unsigned int y[N];
    
    unsigned int c1[2][MAX_SIZE] = {};
    unsigned int c2[2][MAX_SIZE] = {};
    unsigned int c3[2][MAX_SIZE] = {};
    unsigned int c4[2][MAX_SIZE] = {};
    
    x[0] = K;
    
    for(long i = 1; i < N; i++){
        x[i] = (unsigned int)((x[i-1] * (unsigned long long)M ) & 0xFFFFFFFFU);
        
        x[i] %= L;
    }
    
    for(long i = 0; i < N; i++){
        c1[0][x[i] & 0x000000FFU]++;
        c2[0][(x[i] >> 8) & 0x000000FFU]++;
        c3[0][(x[i] >> 16) & 0x000000FFU]++;
        c4[0][(x[i] >> 24)]++;
    }
    
    for(int i = 1; i < MAX_SIZE; i++){
        c1[1][i] = c1[0][i-1] + c1[1][i-1];
        c2[1][i] = c2[0][i-1] + c2[1][i-1];
        c3[1][i] = c3[0][i-1] + c3[1][i-1];
        c4[1][i] = c4[0][i-1] + c4[1][i-1];
    }    
    
    for(long i = 0; i < N; i++){
        y[c1[1][x[i] & 0x000000FFU]++] = x[i];
    }
    
    for(long i = 0; i < N; i++){
        x[c2[1][(y[i] >> 8) & 0x000000FFU]++] = y[i];
    }
    
    for(long i = 0; i < N; i++){
        y[c3[1][(x[i] >> 16) & 0x000000FFU]++] = x[i];
    }
    
    for(long i = 0; i < N; i++){
        if((c4[1][y[i] >> 24]++) % 2 == 0){
            RESULT += y[i];
        }
    }
    
    cout << RESULT % L;
    
    return 0;
}