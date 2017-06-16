#include <iostream>

using namespace std;

unsigned long long countTree(unsigned int N){
    unsigned long long catalan[N+1];

    catalan[0]=catalan[1]=1;    
    
    int i,j;

    for(i=2;i<=N;i++){
        catalan[i]=0;
        
        for(j=0;j<i;j++){
            catalan[i]+=catalan[j]*catalan[i-j-1];
         
            catalan[i]%=1000000000;
         }
    }

    return catalan[N];
}

int main(){
   unsigned int x;
    
   cin >> x;
    
   if(x == 0){
      cout << "0" << endl;

      exit(1);
   }

    cout << countTree(x) << endl;
    
    return 0;
}  