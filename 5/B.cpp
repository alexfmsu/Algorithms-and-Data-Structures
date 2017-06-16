#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Node{

public:
    Node(int _freq = 0, Node *_left = NULL, Node *_right = NULL){
        freq = _freq;
        left = _left;
        right = _right;
    }
    
    int freq;
    int prior;
    
    string name;

private:
    Node *left, *right;
};

class bin_heap{

public:
    bin_heap(int maxsize){
        body = new Node[maxsize + 1];
        
        body_size = maxsize;
        nodes_count = 0;
    }

    void swap(int a, int b){
        std::swap(body[a], body[b]);        
    }
    
    Node get_min(){
        if(nodes_count == 0){
            return body[0];
        }

        Node p = body[1];
        body[1] = body[nodes_count--];

        heapify(1);
        
        return p;
    }
    
    int insert(Node node){
        if(nodes_count > body_size){
            return -1;
        }

        body[++nodes_count] = node;
        
        for(int i = nodes_count; i > 1 && body[i].freq < body[i/2].freq; i /= 2){
            swap(i, i/2);
        }
        
        return nodes_count;
    }

    void heapify(int ind){
        while(1){
            int left = ind + ind;
            int right = left + 1;

            int largest = ind;

            if(left <= nodes_count && body[left].freq < body[ind].freq){
                largest = left;
            }

            if(right <= nodes_count && body[right].freq < body[largest].freq){
                largest = right;
            }

            if(largest == ind){
                break;
            }

            swap(ind, largest);
            
            ind = largest;
        }
    }
    
    ~bin_heap(){};

private:
    int body_size;
    int nodes_count;
    
    Node *body;
};

unsigned sedgwick(string s, unsigned HASHSIZE){
    unsigned h = 0, i, a = 31415, b = 27183;
    
    for(i = 0; i < s.size(); i++){
        h = (a + b) * h % HASHSIZE;
        
        a = (a * b) % (HASHSIZE - 1);
    }
    
    return h;
}


int main(int argc, char** argv){
    int M, N;
    
    cin >> M >> N;
    
    vector<pair<string, pair<int, int> > > v(N);
    vector<string> hash(M);
    
    bin_heap heap(N);
    
    for(int i = 0; i < N; i++){
        Node node;

        int score;
        string name;
        
        cin >> name >> score;
        
        node.freq = score;
        node.name = name;
        node.prior = i;
        
        heap.insert(node);
    }
    
    for(int i = 0; i < v.size(); i++){
        Node node = heap.get_min();
        
        int size = v.size();
        
        int ind = size - i - 1;

        v[ind].second.first = node.freq;
        v[ind].second.second = node.prior;
        v[ind].first = node.name;
        
        heap.heapify(0);
    }
    
    bool stable = false;
    
    while(!stable){
        stable = true;
        
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i].second.first == v[i + 1].second.first && v[i].second.second > v[i + 1].second.second){
                swap(v[i], v[i + 1]);
                
                stable = false;
            }
        }
    }
    
    cout << endl;
    
    for(int i = 0; i < v.size(); i++){
        string name = v[i].first;

        int ind = sedgwick(name, M);
        
        while(hash[ind] != name){
            if(hash[ind] == ""){
                hash[ind] = name;
                
                cout << name << endl;
                
                break;
            }else{
                ind = (ind + 1) % M;
            }
        }
    }
    
    return 0;
}