#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
    string s;
    cin >> s;
    
    int max = 0;
    
    map <string, int> m;
    for (int len = 1; len<=s.length(); len++) {
        for (int i=0; i<=s.length()-len; i++) {
            if (m[s.substr(i, len)]) {m[s.substr(i, len)]++;}
            else {m[s.substr(i, len)] = 1;}
            if (m[s.substr(i, len)]*len > max) {max = m[s.substr(i, len)]*len;}
        }
    }
    
    cout << max;

    return 0;
}