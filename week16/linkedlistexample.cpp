#include <iostream>
using namespace std;

template <class T>
class LListNode {
private:
    T data;
    LListNode<T>* next;

public:
    LListNode(T newData = T(), LListNode<T>* newNext = nullptr) : data(newData), next(newNext) {}
    friend class LList<T>;
};

int main() {
    LListNode<int> node3(3, nullptr); // Create the last node with no next node
    LListNode<int> node2(2, &node3); // Create node2 and link it to node3
    LListNode<int> node1(1, &node2); // Create node1 and link it to node2

    LListNode<int>* currentNode = &node1; // Set the current node pointer to the first node


    return 0;
}
