#include <iostream>

using namespace std;

int main(){
    bool simple[1000];
    
    for(int i = 0; i < 1000; i++){
        simple[i] = false;
    }
    
    simple[101] = true; simple[103] = true; simple[107] = true; simple[109] = true; simple[113] = true; simple[127] = true; simple[131] = true; simple[137] = true; simple[139] = true; simple[149] = true; simple[151] = true; simple[157] = true; simple[163] = true; simple[167] = true; simple[173] = true; simple[179] = true; simple[181] = true; simple[191] = true; simple[193] = true; simple[197] = true; simple[199] = true; simple[211] = true; simple[223] = true; simple[227] = true; simple[229] = true; simple[233] = true; simple[239] = true; simple[241] = true; simple[251] = true; simple[257] = true; simple[263] = true; simple[269] = true; simple[271] = true; simple[277] = true; simple[281] = true; simple[283] = true; simple[293] = true; simple[307] = true; simple[311] = true; simple[313] = true; simple[317] = true; simple[331] = true; simple[337] = true; simple[347] = true; simple[349] = true; simple[353] = true; simple[359] = true; simple[367] = true; simple[373] = true; simple[379] = true; simple[383] = true; simple[389] = true; simple[397] = true; simple[401] = true; simple[409] = true; simple[419] = true; simple[421] = true; simple[431] = true; simple[433] = true; simple[439] = true; simple[443] = true; simple[449] = true; simple[457] = true; simple[461] = true; simple[463] = true; simple[467] = true; simple[479] = true; simple[487] = true; simple[491] = true; simple[499] = true; simple[503] = true; simple[509] = true; simple[521] = true; simple[523] = true; simple[541] = true; simple[547] = true; simple[557] = true; simple[563] = true; simple[569] = true; simple[571] = true; simple[577] = true; simple[587] = true; simple[593] = true; simple[599] = true; simple[601] = true; simple[607] = true; simple[613] = true; simple[617] = true; simple[619] = true; simple[631] = true; simple[641] = true; simple[643] = true; simple[647] = true; simple[653] = true; simple[659] = true; simple[661] = true; simple[673] = true; simple[677] = true; simple[683] = true; simple[691] = true; simple[701] = true; simple[709] = true; simple[719] = true; simple[727] = true; simple[733] = true; simple[739] = true; simple[743] = true; simple[751] = true; simple[757] = true; simple[761] = true; simple[769] = true; simple[773] = true; simple[787] = true; simple[797] = true; simple[809] = true; simple[811] = true; simple[821] = true; simple[823] = true; simple[827] = true; simple[829] = true; simple[839] = true; simple[853] = true; simple[857] = true; simple[859] = true; simple[863] = true; simple[877] = true; simple[881] = true; simple[883] = true; simple[887] = true; simple[907] = true; simple[911] = true; simple[919] = true; simple[929] = true; simple[937] = true; simple[941] = true; simple[947] = true; simple[953] = true; simple[967] = true; simple[971] = true; simple[977] = true; simple[983] = true; simple[991] = true; simple[997] = true; 
    
    int N;
    
    cin >> N;
    
    long long a[N+1][10][10];
    
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                a[i][j][k] = 0;
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){ 
                a[3][j][i] += simple[k*100 + j*10 + i];
            }
        }
    }
                
    long long tmp = 0;

    for(int t = 4; t < N+1; t++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                tmp = 0;

                for(int k = 1; k < 10; k++){
                    if(simple[k*100 + j*10 + i]){
                        tmp = (tmp + a[t-1][k][j] % 1000000009) % 1000000009;
                    }
                }

                a[t][j][i] = tmp;
            }
        }
    }
        
    long long ans = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ans = (ans + a[N][j][i] % 1000000009) % 1000000009;
        }
    }

    cout << ans;
    
    return 0;
}