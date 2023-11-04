#include <iostream>
#include <vector>

using namespace std;

template <class T>

class Queue {
    private:
        int frontptr = 0;
        int backptr = 0;
        vector<T> v;

    public:
    void enqueue(T data) {
        v.push_back(data);
        backptr++;
    }

    T dequeue() { 
        T queue = v[frontptr++];
        backptr--;

        if(empty()) {
            reset();
        }

        return queue;
    }

    T first() {
        return v[frontptr];
    }

    int size() {
        return backptr;
    }

    bool empty() {
        return backptr == 0;
    }

    void reset() {
        v.clear();
        frontptr = 0;
        backptr = 0;
    }
};

int main() {
    Queue<int> v;

    v.enqueue(1);
    v.enqueue(9);
    v.enqueue(5);
    v.enqueue(6);
    v.enqueue(3);
    v.enqueue(2);

    cout<<"size of v: "<<v.size()<<endl;

    v.reset();

    cout<<"size of v: "<<v.size()<<endl;

    v.enqueue(1);
    v.enqueue(9);
    v.enqueue(5);
    v.enqueue(6);
    v.enqueue(3);
    v.enqueue(2);

    cout<<"size of v: "<<v.size()<<endl;

    v.dequeue();

    cout<<"size of v: "<<v.size()<<endl;

    v.dequeue();
    v.dequeue();
    cout<<"size of v: "<<v.size()<<endl;
}

