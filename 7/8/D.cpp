#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i=0;i<n;i++)
#define vfor(type, var, iter) for(vector<type>::iterator iter = var.begin(); iter != var.end(); ++iter)
using namespace std;

struct PrimeCaves {
  int caves;
  int start;
  PrimeCaves(int caves, int start) :
  caves(caves), start(start) {}
};

bool prime(int n){
  if(n == 1) return false;
  if(n == 2) return true;
  for(int i=2;i<sqrt(n)+1;i++)
    if(n % i == 0) return false;
  return true;
}

int main(void){
  vector<PrimeCaves> dataset;
  int c, s;

  while(true){
    cin >> c >> s;
    if(c == 0) break;
    dataset.push_back(PrimeCaves(c, s));
  }

  vfor(PrimeCaves, dataset, i){
    PrimeCaves pc = *i;
    c = pc.caves;
    s = pc.start;
  }
   return 0;
}