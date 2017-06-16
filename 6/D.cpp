#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
 
ll a[505][505];
ll d[505][505];
const ll INF = 1e15;
vvi g, gw;
 
int main() {
 int n, M;
 cin >> n >> M;
 for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = a[i][j] = INF;
 vi a0(n + 1);
 for (int i = 1; i <= n; ++i) {
  cin >> a0[i];
  a[i][i] = a0[i];
 }
 g.resize(n + 1);
 gw.resize(n + 1);
 for (int i = 0; i < M; ++i) {
  int u, v, c;
  cin >> u >> v >> c;
  g[u].push_back(v);
  gw[u].push_back(c);
 }
 for (int s = 1; s <= n; ++s) {
  d[s][s] = 0;
  set<pii> q;
  q.insert(pii(0, s));
  while (!q.empty()) {
   int v = q.begin()->second;
   q.erase(q.begin());
   for (int i = 0; i < g[v].size(); ++i) {
    int nv = g[v][i];
    ll cand = d[s][v] + gw[v][i];
    if (cand < d[s][nv]) {
     q.erase(pii(d[s][nv], nv));
     d[s][nv] = cand;
     q.insert(pii(d[s][nv], nv));
    }
   }
  }
 }
 for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j) a[i][j] = d[i][j];
 int m = n;
 vl u(n + 1), v(m + 1), p(m + 1), way(m + 1);
 for (int i = 1; i <= n; ++i) {
  p[0] = i;
  ll j0 = 0;
  vl minv(m + 1, INF);
  vector<char> used(m + 1, false);
  do {
   used[j0] = true;
   ll i0 = p[j0], delta = INF, j1;
   for (int j = 1; j <= m; ++j)
    if (!used[j]) {
     ll cur = a[i0][j] - u[i0] - v[j];
     if (cur < minv[j])
      minv[j] = cur, way[j] = j0;
     if (minv[j] < delta)
      delta = minv[j], j1 = j;
    }
   for (int j = 0; j <= m; ++j)
    if (used[j])
     u[p[j]] += delta, v[j] -= delta;
    else
     minv[j] -= delta;
   j0 = j1;
  } while (p[j0] != 0);
  do {
   int j1 = way[j0];
   p[j0] = p[j1];
   j0 = j1;
  } while (j0);
 }
 cout << -v[0] << endl;
 return 0;
}