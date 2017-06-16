#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool pred(const std::pair< int, int > &a, const std::pair< int, int > &b){
    return a.second > b.second || (a.second == b.second && a.first < b.first);
}
int main(){
    map <char, int> x;

    char c;

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        // if(abs(s[i] - 'A') > 26){
        //     return 0;
        // }

        x[s[i]]++;
    }

    std::vector< std::pair< char, int > > vec(x.begin(), x.end() );
    std::sort(vec.begin(), vec.end(), pred);

    for (auto p : vec){
        std::cout << p.first << ' ' << p.second << std::endl;
    }

    return 0;
}