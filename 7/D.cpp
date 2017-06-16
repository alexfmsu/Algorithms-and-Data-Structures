#include <iostream>
#include <list>

using namespace std;
 
class Graph{
    int V;  
    list<int> *adj;

public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
 
    void addEdge(int v, int w);
 
    int isEulerian();
 
    bool isConnected();
 
    void DFSUtil(int v, bool visited[]);
};
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);  
}
 
void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
bool Graph::isConnected(){
    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;
 
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;
 
    if (i == V)
        return true;
 
    DFSUtil(i, visited);
 
    for (i = 0; i < V; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;
 
    return true;
}
 
 int Graph::isEulerian(){
    if (isConnected() == false)
        return 0;
 
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;
 
    if (odd > 2)
        return 0;
 
    return (odd)? 1 : 2;
}
 
void test(Graph &g){
    int res = g.isEulerian();
    if (res == 0)
        cout << "NO\n";
    else if (res == 1)
        cout << "YES\n";
    else
        cout << "YES\n";
}
 
int main(){
    int n, m;

    cin >> n >> m;
    
    Graph g1(n);

    for(int i = 0; i < m; i++){
        int x, y;

        cin >> x >> y;

        g1.addEdge(x-1, y-1);    
    }
            
    test(g1);

    return 0;
}