#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char** argv){
    string s;
    cin >> s;
    
    int h = 0;
    int N = 0;
    
    int len = s.length();
    
    for(int i = 0; i < len; i++){
        char c = s[i];

        if(h == 0 && c == 'b'){
            h++;
        }else if(h > 0){
            switch(c){
                case 'w': N++;
                          break;
                case ')': h--;
                          break;
                case '(': h++;
                          break;
                default:  ;
            }
        }
    }
    
    cout << N << endl;
    
    return 0;
}