#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    std::string str1;
    std::string str2;
    
    std::cin >> str1;
    std::cin >> str2;
    
    int len1 = str1.length();
    int len2 = str2.length();
    
    vector<vector<int> > data;
    
    for(int i = 0; i <= len2; i++){
        data.push_back(std::vector<int>(len1 + 1));
    }
    
    for(int i = 0; i <= len1; i++){
        data[0][i] = i;
    }
    
    for(int i = 1; i <= len2; i++){
        data[i][0] = i;
    }
    
    for(int j = 1; j <= len2; j++){
        for(int i = 1; i <= len1; i++){
            int c = 0;
            
            if(str1.at(i - 1) != str2.at(j - 1)){
                c = 1;
            }
            
            int min = std::min({ data[j][i - 1] + 1, data[j - 1][i] + 1, data[j - 1][i - 1] + c});
            
            data[j][i] = min;
        }
    }
    
    cout << data[len2][len1];
    
    return 0;
}