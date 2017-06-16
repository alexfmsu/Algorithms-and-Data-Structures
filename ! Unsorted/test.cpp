#include <iostream>

using namespace std;
void print_x();
int main(){
int x=1, y=2, z;

z = x & y | (x && y);
cout << z;
return z;
}