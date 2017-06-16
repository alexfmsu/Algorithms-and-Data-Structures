#include <iostream>
#include <cstdio>

using namespace std;

void mergeWithoutExtraMemory(int *a, int p, int q, int r){
    int i = p;
    int k, temp;
    
    while(i <= q){
        if(a[i] > a[q+1]){
            temp = a[q+1];
            
            for(k = q+2 ; k <=r; k++){
                if (a[k] > a[i]){
                    break;
                }

                a[k - 1] = a[k];
            }

            a[k-1] = a[i];
            a[i] = temp;
        }

        i++;
    }
}

void mergeSortWithoutExtraMemory(int *a, int p, int r){
    if (p < r){
        int q = (p+r)/2;

        mergeSortWithoutExtraMemory(a, p, q);
        mergeSortWithoutExtraMemory(a, q+1, r);
        mergeWithoutExtraMemory(a, p, q, r);
    }
}

int main(){
    int n;
    
    cin >> n;
    n *= 2;
    
    if(n == 0){
        cout << "0" << endl;

        return 0;
    }
    
    int x[n];
    
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    mergeSortWithoutExtraMemory(x, 0, n - 1);
    
    long sum = 0;
    
    // for (int i = 0; i < n; i++){
    //     cout << x[i] << " ";
    // }
    
    for (int i = 0; i < n; i+=2){
        sum += x[i];
    }
    
    long ost = (sum % 1000000000);

    printf("%ld\n", ost);
    // cout >> ost << endl;
    // int ost[9];
    
    // int count = -1;

    // for(int i = 0; i < 9; i++){
    //     if(sum == 0){
    //         break;
    //     }

    //     ost[9-i-1] = (sum % 10);
    //     sum /= 10;

    //     count++;
    // }

    // while(count >= 0){
    //     cout << ost[9-count-1];

    //     count--;
    // }

    // cout << endl;

    return 0;
}