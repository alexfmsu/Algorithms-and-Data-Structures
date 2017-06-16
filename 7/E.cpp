#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct point{
    int x;
    int y;
    
    point(){}
    point(int x_in, int y_in) {
        x = x_in;
        y = y_in;
    }
};

struct table{
    int N, M;
    
    queue <point> q;
    vector <vector<char> > body;
    vector <vector<int> > tab;

    table (int N_in, int M_in){
        N = N_in;
        M = M_in;

        body = vector <vector<char> > (N, vector<char>(M));
        tab = vector <vector<int> > (N, vector<int>(M));
        
        for(int i=0; i<N; i++)
            for (int j=0; j<M; j++) tab[i][j] = 2000000000;
    }
    
    
    void set(int x, int y, char val) {
        body[x][y] = val;
    } 
    
    char is (int x, int y) {
        if (x<0 || y<0 || x>=N || y>=M) return '+';
        return body[x][y];
    }
    
    void print_maze () {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cout << body[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    void print_tab () {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cout << tab[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    void compute (int x, int y) {
        if (is(x+1,y)!='+' && tab[x+1][y]>tab[x][y]+1){
            tab[x+1][y] = tab[x][y]+1;
            point tmp(x+1, y);
            q.push(tmp);
        }
        if (is(x-1,y)!='+' && tab[x-1][y]>tab[x][y]+1){
            tab[x-1][y] = tab[x][y]+1;
            point tmp(x-1, y);
            q.push(tmp);
        }
        if (is(x,y+1)!='+' && tab[x][y+1]>tab[x][y]+1){
            tab[x][y+1] = tab[x][y]+1;
            point tmp(x, y+1);
            q.push(tmp);
        }
        if (is(x,y-1)!='+' && tab[x][y-1]>tab[x][y]+1){
            tab[x][y-1] = tab[x][y]+1;
            point tmp(x, y-1);
            q.push(tmp);
        }
    }
    
    void find_shortest_path(int x, int y) {
        point tmp(x, y);
        q.push(tmp);
        tab[x][y] = 0;  
        while(q.size()) {
            tmp = q.front();
            compute(tmp.x, tmp.y);
            q.pop();
        }
    }
        

};

int main(){
    int N, M;
    
    cin >> N >> M;
    
    string s;
    
    point in;
    point out;
    
    table maze(N, M);

    for(int i = 0; i < N; i++){
        cin >> s;

        for(int j = 0; j < M; j++){
            maze.set(i, j, s[j]);
            
            if(s[j] == '@'){
                in.x = i;
                in.y = j;
            }
            
            if(s[j] == '#'){
                out.x = i;
                out.y = j;
            }
        }
    }
    
    maze.find_shortest_path(in.x, in.y);

    cout << maze.tab[out.x][out.y];
    
    return 0;
}