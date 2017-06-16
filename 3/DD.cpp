# include <iostream>
# include <cstring>
# include <vector>

using namespace std;

vector<int> prefix(string s){
    int n = s.size();
    
    vector<int> x(n);
    
    for(int i = 1; i < n; i++){
        int j = x[i - 1];
        
        while(j > 0 && s[i] != s[j]){
            j = x[j - 1];
        }
        
        if(s[i] == s[j]){
            j++;
        }
        
        x[i] = j;
    }
    
    return x;
}

int main (){
    string s;
    
    cin >> s;

    cout << s.size() - prefix(s).back();

    return 0;
}