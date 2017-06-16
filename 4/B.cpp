#include <iostream>
#include <string>

using namespace std;


class UserTable{

public:
    string phone;
    string username;
    UserTable* next;
    
    UserTable(){
        next = NULL;
    }

    UserTable(string _username, string _phone){
        username = _username;
        phone = _phone;

        next = NULL;
    }
};

class Phonebook{
    UserTable *head;
    
    void error(){
        cout << "ERROR" << endl;
    }
    
    public:
        Phonebook(){
            head = new UserTable();
        }

        void add(string username, string phone){
            if(!head->next){
                head->next = new UserTable(username, phone);
                
                return;
            }else{
                UserTable *ut = new UserTable ();
                
                ut = head;
                
                while(ut->next){
                    if(username == ut->next->username){
                        error();

                        return;
                    }

                    ut = ut->next;
                }

                ut->next = new UserTable(username, phone);
            }
        }

        void remove(string username){
            UserTable *ut = new UserTable();
            
            ut = head;

            while(ut->next){
                if(username == ut->next->username){
                    ut->next = ut->next->next;

                    return;
                }

                ut = ut->next;
            }

            error();
        }

        void modify(string username, string phone){
            UserTable *ut = new UserTable ();
            
            ut = head;
            
            while(ut->next){
                if(username == ut->next->username){
                    ut->next->phone = phone;

                    return;
                }

                ut = ut->next;
            }

            error();
        }

        void print(string username){
            UserTable *ut = new UserTable ();
            
            ut = head;
            
            while(ut->next){
                if(username == ut->next->username){
                    cout << ut->next->username << ' ' << ut->next->phone << endl;
                    
                    return;
                }

                ut = ut->next;
            }

            error();
        }
};

int main(){
    int N;
    
    string command;
    string username;
    string phone;
    
    Phonebook p;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> command;

        if(command == "ADD"){
            cin >> username >> phone;
            
            p.add(username, phone);
            
            continue;
        }

        if(command == "DELETE"){
            cin >> username;
            
            p.remove(username);
            
            continue;
        }

        if(command == "PRINT"){
            cin >> username;
            
            p.print(username);
            
            continue;
        }

        if(command == "EDITPHONE"){
            cin >> username >> phone;
            
            p.modify(username, phone);
            
            continue;
        }
        
        cout << "ERROR" << endl;
    }
    
    return 0;
}