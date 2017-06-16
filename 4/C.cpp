#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

class Station{

public:
    string oper;
    
    long X, Y, R;
    
    void set(string _oper, long _X, long _Y, long _R){
        oper = _oper;

        X = _X;
        Y = _Y;
        R = _R;
    }
};

class Operator{

public:
    string name;
    
    int station_count;
};

double distance(double x1, double x2, double y1, double y2){
    double dx = x1 - x2;
    double dy = y1 - y2;

    return sqrt(dx*dx + dy*dy);
}

void add_station(vector <Operator> &opers, Station st, long client_a, long client_b) {
    for (int i = 0; i < opers.size(); i++){
        if (st.oper == opers[i].name) { 
            if(distance(client_a, st.X, client_b, st.Y) <= st.R){
                opers[i].station_count++;
            }
            
            return;
        }
    }
    
    Operator op;
    op.name = st.oper;
    op.station_count = 0;
    
    if(distance(client_a, st.X, client_b, st.Y) <= st.R){
        op.station_count++;
    }

    opers.push_back(op);
}   

int main(){
    string str;
    
    vector <Station> stations;
    vector <Operator> opers;
    
    Station st;

    int N;
    
    cin >> N;
    
    long X, Y, R;
    
    for(int i = 0; i < N; i++){
        cin >> str;
        cin >> X >> Y >> R;

        st.set(str, X, Y, R);
        
        stations.push_back(st);
    }

    long client_a, client_b;
    
    cin >> client_a >> client_b;
    
    for(int i = 0; i < N; i++){
        add_station(opers, stations[i], client_a, client_b);
    }   
    
    cout << opers.size() << endl;
    
    for(int i = 0; i < opers.size(); i++){
        cout << opers[i].name << ' ' << opers[i].station_count << endl; 
    }

    return 0;
}
