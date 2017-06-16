#include <iostream>
#include <string>

using namespace std;

string str1, str2;

int n;

bool is_substr(int k){
    for(int i = 0; i < n; i++){
        if (str1[i] != str2[i % (k + 1)]) {
            return false;
        }
    }

    return true;
}

int main(){
    cin >> str1;
    
    n = str1.length();
    
    for(int i = 0; i < n; i++){
        str2 = "";
        
        for(int j = 0; j <= i; j++){
            str2 += str1[j];
        }

        if(is_substr(i)){
            cout << i+1;
            
            break;
        }
    }
}