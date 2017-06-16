#include <iostream>

using namespace std;

void print_grey(string str){
    string left_nulls = "0" + str;
    
    string grey="";
    
    for(int i = 0; i < str.length(); i++){
        grey += (str[i] != left_nulls[i] ) ? "1" : "0";
    }

    cout << grey << endl;
}

void get_str(int x, string prefix){
    if(x == 0){
        print_grey(prefix);
    }else{
        get_str(x-1, prefix + "0");
        get_str(x-1, prefix + "1");
    }
}

int main(){
    int n;
    
    cin >> n;
    
    get_str(n, "");
    
    return 0;
}