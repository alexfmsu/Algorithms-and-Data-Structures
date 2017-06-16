#include <iostream>
#include <cstdio>

using namespace std;


void merge(int a[], int b[], int c, int d, int e)
{
int p1=c, p2=d, pres=c;
while (p1 < d && p2 < e)
if (a[p1] < a[p2])
b[pres++] = a[p1++];
else
b[pres++] = a[p2++];
while (p1 < d)
b[pres++]=a[p1++];
while (p2 < e)
b[pres++]=a[p2++];
}

void merge_sort(int a[], int n)
{
int *temp, *a2=a, *b, *b2;
b = new int[n];
int c, k = 1, d, e;
b2=b;
while (k <= 2*n) {
for (c=0; c<n; c+=k*2) {
d=c+k<n?c+k:n;
e=c+2*k<n?c+2*k:n;
merge(a2, b, c, d, e);
}
temp = a2; a2 = b; b = temp;
k *= 2;
}
for (c=0; c<n; c++)
a[c] = a2[c];
delete[] b2;
}

int main(){
    long n;
    
    cin >> n;

    n *= 2;
    
    if(n == 0){
        cout << "0" << endl;

        return 0;
    }
    
    int x[n];
    
    for(long i = 0; i < n; i++){
        cin >> x[i];
    }
        
    merge_sort(x, n);
    
    long sum = 0;
    
    long i;

    for(i = 0; i < n; i += 2){
        sum += x[i];
    }
    
    long ost = (sum % 1000000000);
    
    cout << ost << endl;
    
    return 0;
}