#include <iostream>

using namespace std;

int main(){
    int n;
    int x;
    int max = 0;
    int second_max = 0;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> x;

        if(x<max){
            if(x>second_max){
                second_max=x;
            }

            continue;
        }

        if(x>=max){
            second_max=max;
            max=x;
        }

    }
    cout << second_max << endl;
    
    return 0;
}