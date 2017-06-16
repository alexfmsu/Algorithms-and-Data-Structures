#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node {
    public:
    node *parent;
    string str;
    bool r;
    vector <node*> children;
    
    node(node* par) {
        parent = par;
        str = "";
    }
    
};

void createTree (node *par) {
    node *elem;
    string swp;
    char ch;

    while (cin >> ch) {
        switch (ch) {
            case '(':
                elem = new node(par);
                // par->children.push_back(elem);
                // createTree(elem);
                // cout << '(' << endl;
                break;
            // case ')':
            //     cout << ')' << endl;
            //     return;
            // case 'R':
            //     cout << "R. " << endl << elem->children.back()->str << ' ';
            //      swp = "";
            //      for (int i=elem->children.back()->str.size()-1; i>=0; i--) {
            //              swp += elem->children.back()->str[i];
            //      }
            //      elem->children.back()->str = swp;
            //     cout << elem->children.back()->str << endl;
            //     break;  
            // case ',':
            //     cout << ',' << endl;
            //     break;
            default :
                cout << ch << endl;
                par->str += ch;
                break;
    
        }
    }
}

void printTree(node *elem, int level) {
    for (int i=0; i<level; i++) cout << ' ';
    cout << '(';

    for (int i=0; i<level; i++) cout << ' ';
//  if (elem->str.size()) cout << elem->str;

    for (int i=0; i<elem->children.size(); i++) {
        cout << endl;
        printTree(elem->children[i], level+1);
    }

    for (int i=0; i<level; i++) cout << ' ';
    cout << ')';
}
/*
int countTree (node *elem, bool black) {
    int count=0;
    if (elem->color == 'b') black = true;
    if (black && elem->color == 'w') count++;
    for (int i=0; i<elem->children.size(); i++) {
        count += countTree(elem->children[i], black);
    }
    return count;
}
*/
int main () {
    
    char ch;
    
    node *root;
    
    createTree(root);

    cout << (root->children).size();
    
//  printTree (root, 0);
//  cout << countTree(root, false);
    
    return 0;
}