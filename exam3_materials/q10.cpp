#include <iostream>
#include <vector>

using namespace std;

class Furniture {
public:
    virtual void display() {

    }
};

class Chair: public Furniture {
public:
    void display() {
        cout<<"This is a chair"<<endl;
    }
};

int main() {
    vector <Furniture*> v;
    Chair chair1;
    Chair chair2;
    Chair chair3;

    v.push_back(&chair1);
    v.push_back(&chair2);
    v.push_back(&chair3);

    for(Furniture* item : v) {
        item->display();
    }
    return 0;
}