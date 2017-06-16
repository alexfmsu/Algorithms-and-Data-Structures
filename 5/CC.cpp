#include <iostream>
#include <cstring>

using namespace std;

struct node{
    char c;
    
    node* prev;
    node* left;
    node* right;
};

void print_tree(node* t, int level){
    cout << level << ": " << t->c << endl;
    
    if(t->left != NULL){
        print_tree(t->left, ++level);
    }
    
    if(t->right != NULL){
        print_tree(t->right, ++level);
    }
}

int main(){
    string s;
    
    cin >> s;
    
    node tree;
    tree.prev = NULL;
    tree.left = NULL;
    tree.right = NULL;
    
    node* t = &tree;
    
    for(int i = 0; i < s.length(); i++){
        // cout << s[i] << endl;
        
        if(t->prev == NULL){
            t->c = s[i];
            
            t->prev = t;
            
            cout << "0: " << s[i] << endl;
        }else if((t->c) > s[i]){
            t->left = new node();
            t->left->c = s[i];
            t->left->prev = t;
            t = t->left;
            
            cout << "left: " << s[i] << endl; 
        }else{
            t->right = new node();
            t->right->c = s[i];
            t->right->prev = t;
            t = t->right;
            
            cout << "right: " << s[i] << endl; 
        }
    }
    
    print_tree(&tree, 0);
    
    return 0;
}