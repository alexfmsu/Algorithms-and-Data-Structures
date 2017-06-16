#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ft first
#define sd second
#define mk make_pair
#define ms(a,v) memset(a,v,sizeof(a))
using namespace std;
 
const int lim=2e5+5;
const int M=1e9+7;
vector<ll> size(lim,-1);
vector<ll> parent(lim);
 
 
// initialize sets of size=1 from 1 to n
void init(ll n)
{   
    
 for(ll i=1;i<=n;i++)
 {
  parent[i]=i;
  size[i]=1;
    }
}
 
 
// find the parent of node x
ll find(ll x)
{  
    if(parent[x]==x)
    return x;
 
 return parent[x]=find(parent[x]);
 
}
 
// union of 2 sets. a,b are two nodes 
void _union(ll a,ll b)
{   
    
 ll ra,rb;
 
 ra=find(a);
 rb=find(b);
 
 if(ra==rb)
 return;
 
 if(size[ra]<size[rb])
 {
  parent[ra]=rb;
  size[rb]+=size[ra];
 }
 
 else
 {
  parent[rb]=ra;
  size[ra]+=size[rb];
 }
 
}
 
 
struct e
{
   ll u,v,wt; 
};
 
e edge[lim],mst[lim];
 
bool cmp(e a,e b)
{
  return a.wt<b.wt; 
}
 
ll kruskal(ll n)
{
    int cnt=0;
    int cur=0;
    ll totalcost=0;
   
    while(cnt<n-1)
 {
  ll u=edge[cur].u;
  ll v=edge[cur].v;
  ll wt=edge[cur++].wt;
  
  if( find(u)!=find(v) )
  {
   mst[cnt].u=u;
   mst[cnt].v=v;
   mst[cnt++].wt=wt;
   totalcost+=wt;
   _union(u,v);
  }
  
 }
 
// for(cur=0;cur<n-1;cur++)
// cout<<mst[cur].u<<"  "<<mst[cur].v<<"  "<<mst[cur].wt<<endl;
 return totalcost; 
}
 
struct Point
{
 ll x,y,idx;  
};
 
bool cmpx(Point a,Point b)
{
 return a.x<b.x;
}
 
bool cmpy(Point a,Point b)
{
 return a.y<b.y;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  //  freopen("input.txt", "r", stdin);
 
 ll n,i;
 cin>>n;
 
 Point p[n+10];
 
 for(i=0;i<n;i++)
 {
  cin>>p[i].x>>p[i].y;
  p[i].idx=i+1;
 }
 
 sort(p,p+n,cmpx);
 for(i=0;i<n-1;i++)
 {
  edge[i].u=p[i].idx;
  edge[i].v=p[i+1].idx;
  edge[i].wt=p[i+1].x-p[i].x;
 }
 sort(p,p+n,cmpy);
 for(int j=0;j<n-1;j++)
 {
  edge[i].u=p[j].idx;
  edge[i].v=p[j+1].idx;
  edge[i].wt=p[j+1].y-p[j].y;
  i++;
 }
 
// for(i=0;i<2*n-2;i++)
// cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].wt<<endl;
 sort(edge,edge+(2*n-2),cmp);
 
 init(n);
 cout<<kruskal(n);
 return 0;
}