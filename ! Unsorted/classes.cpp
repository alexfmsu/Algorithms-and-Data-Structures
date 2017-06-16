#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

struct claim {
    double begin;
    double end;
    int audit;

    bool operator < (const claim & val) const {return begin < val.begin;}
};

typedef vector<claim> listClaim;
typedef listClaim::iterator itrClaim;

int assignment(listClaim &val) {
    listClaim room;
    itrClaim itr;

    for(itrClaim i=val.begin(); i != val.end(); i++){
        itr=room.begin();
        
        while((itr != room.end()) && (i->begin <= itr->end)) ++itr;
            if (itr != room.end()){
                i->audit = itr->audit;
                *itr = *i;
        }else{
            i->audit=room.size()+1;
            room.push_back(*i);
        }
    }

    return room.size();
}

int main() {
    int n;
    
    cin >>n;

    listClaim x;
    
    claim temp;
    
    int i=0;
    
    while(i < n){
        cin >>temp.begin;
    
        cin >>temp.end;
        temp.audit=-1;
        if (temp.begin < temp.end) {
            i++;
            x.push_back(temp);
        }
        else cout << "Неправильно введено время заявки. Введите еше раз\n";
    }
    
    sort(x.begin(), x.end());

    cout << assignment(x) << endl;
    
    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <vector>

// using namespace std;

// typedef pair<long, long> cut;

// void print(vector<cut> x){
//     for(int i = 0; i < x.size(); i++){
//         cout << "(" << x[i].first << "," << x[i].second << ") ";
//     }

//     cout << endl;
// }

// bool pair_compare(const cut& a, const cut& b){
//     return a.second < b.second;
//     // return a.second < b.second;
// }

// bool intersect(cut a, cut b){
//     return (a.first < b.second && a.second >= b.first) || (b.first < a.second && b.second >= a.first);
// }

// int main(){
//     int n;

//     cin >> n;

//     if(n == 0){
//         cout << "0" << endl;

//         return 0;
//     }

//     long a, b;

//     vector<cut> x;

//     for(int i = 0; i < n; i++){
//         cin >> a >> b;

//         if(a < 0 || b < 0){
//             cout << "0" << endl;

//             return 0;
//         }

//         cut tmp = make_pair(a, b);

//         x.push_back(tmp);
//     }

//     int count = 0;

//     sort(x.begin(), x.end(), pair_compare);

//     int x_size = x.size();

//     // print(x);

//     while(x_size > 0){
//         cut tmp = x[0];
        
//         count++;
        
//         for(int i = 0; i < x_size; i++){
//             if(intersect(x[i], tmp)){
//                 // cout << "123" << endl;
//                 x.erase(x.begin() + i);
//                 // cout << "count = " << count << ", after remove: ";
//                 // print(x);    
//                 x_size--;
//             }
//         }
//     }

//     cout << count << endl;
    
//     return 0;
// }