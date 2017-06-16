#include <iostream>
#include <cstdio>

using namespace std;

int get_common(int* x1, int n1, int* x2, int n2){
    int i = 0;
    int j = 0;
    
    int count = 0;

    while(n1 > i && n2 > j){
        if(x1[i] < x2[j]){ 
            i++;
        }else if(x2[j] < x1[i]){
            j++;
       }else{
            count++;    
        
            i++;
            j++;
        }
    }
    
    return count;
}
 
int main(void) {
    int n1, n2;

    cin >> n1 >> n2;

    int x1[n1];
    int x2[n2];

    for(int i = 0; i < n1; i++){
        cin >> x1[i];
    }

    for(int i = 0; i < n2; i++){
        cin >> x2[i];
    }

    cout << get_common(x1, n1, x2, n2);
 
    return 0;
}