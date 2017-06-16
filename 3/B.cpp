#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;


int main () {
    long N;
    long K;

    long position = 0;
    
    stringstream s;
    string s_num;
    string s_k;
    
    cin >> N >> K;
    
    s << K;
    s >> s_k;
    
    for(long i = 1; i <= N; i++){
        stringstream s;

        s << i;
        s >> s_num;
        
        if(s_k.compare(s_num) >= 0){
            position++;
        }
    }
    
    cout << position << endl;
    
    return 0;
}