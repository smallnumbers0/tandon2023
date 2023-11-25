//Homework 15: Linked Lists & File Reading

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

    ~Friend() {}
};
//
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
        void display() { //test to see if linked list is linking properly
            Friend *current = head;
            while (current != nullptr) {
                cout <<current->full_name<<" "<< current->amount_paid<< endl;
                current = current->next;
            }
        }
};



int main() {
    double total = 0;
    double average;
    int num_friends = 0;
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
        total += amount_paid;
        num_friends++;
        input_file.ignore(9999, ' ');
        getline(input_file, full_name);
        friends.insert(full_name, amount_paid);

    }
    
    input_file.close();
    friends.display();
    average = total / num_friends;

    Friend* current;
    current = friends.head;
    while (current != nullptr) {
        current->amount_owed = current->amount_paid - average;
        if(current->amount_owed == 0) {
            cout<<current->full_name<<" is all set."<<endl;
        }
        current = current->next;
    }

    current = friends.head;
    while (current != nullptr) {
        if (current->amount_owed > 0) {
            Friend* temp = friends.head; //pointing to friends who should get money owed
            while (temp != nullptr) {
                if (temp->amount_owed < 0) {
                    double transfer_amount;
                    if (current->amount_owed < -temp->amount_owed) {
                        transfer_amount = current->amount_owed;
                    } else {
                        transfer_amount = -temp->amount_owed;
                    }
                    temp->amount_owed += transfer_amount;
                    current->amount_owed -= transfer_amount;
                    cout << current->full_name << " gets $" << transfer_amount << " from " << temp->full_name << endl;
                    if (current->amount_owed <= 0) {
                        break;  
                    }
                }

                temp = temp->next;
            }
        }
        current = current->next;
    }

    cout<<"Everyone should have spent $"<<average<<endl;

    current = friends.head;
    while (current != nullptr) {
        Friend* next = current->next;
        delete current;
        current = next;
    }

    // delete current;

    return 0;
}
