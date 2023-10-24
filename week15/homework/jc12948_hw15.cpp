//Homework 10: Linked Lists & File Reading

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Friend {
    string full_name;
    double amount_paid;
    double amount_owed;
    Friend *next; //pointer pointing to next Friend

    Friend(const string &n, double paid) {
        full_name = n;
        amount_paid = paid;
        amount_owed = 0;
        next = nullptr;
    }
};

class FriendsList {
    public:
        Friend *head; //head ptr

        FriendsList() {
           head = nullptr;
        }

        void insert(const string &name, double paid) {
            Friend *new_friend = new Friend(name, paid);

            if(head == nullptr) {
                head = new_friend;
            }
            else {
                Friend *current = head;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = new_friend;
            } 
        }
        void display() {
        Friend *current = head;
        while (current != nullptr) {
            cout <<current->full_name<<" "<< current->amount_paid<< endl;
            current = current->next;
        }
    }

};

int main() {
    string file_name;
    cout<<"Please enter file name: "<<endl;
    cin>>file_name;

    FriendsList friends;

    ifstream input_file;
    input_file.open(file_name);
    if(!input_file) {
        cout<<"Error, file did not open."<<endl;
        exit(1);
    }

    while(!input_file.eof()) {
        string full_name;
        double amount_paid;
        input_file>>amount_paid;
        input_file.ignore(9999, ' ');
        getline(input_file, full_name);
        friends.insert(full_name, amount_paid);

    }
    
    input_file.close();
    friends.display();

    return 0;
}


