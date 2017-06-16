
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class node{

public:
    node(node* _node){
        prev = _node;
        word = "";
    }
    
    string word;
    
    node *prev;
    
    vector<node*> next;
};

void build_tree(node *prev){
    char c;
    
    node* elem;

    while(cin >> c){
        if(c == '('){
            elem = new node(prev);
            
            prev->next.push_back(elem);
            
            build_tree(elem);
        }else if(c != '(' && c != ')' && c != 'R'){
            prev->word += c;
        }
        
        cout << c << endl;
    }
}

void print_empties(int count){
    for(int i = 0; i < count; i++){
        cout << " ";
    }
}

void print_tree(node *elem, int depth){
    print_empties(depth);
    cout << '(';
    print_empties(depth);
    
    for(int i = 0; i < elem->next.size(); i++){
        cout << endl;
        
        print_tree(elem->next[i], depth + 1);
    }
    
    print_empties(depth);
    cout << ')';
}

int main(){
    node *head;
    
    build_tree(head);

    cout << head->next.size();
    
    return 0;
}