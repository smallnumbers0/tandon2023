//Winter 2023
/*
1. A
2. C
3. C
4. Base:: val = x;
5.
BSTNode *temp = theNode;
BSTNode *parent = temp->parent;

if(parent->left == temp) {
    cout<<"It is left child."<<endl;
}
else {
    cout<<"It is the right child."<<endl;
}

6. I would split the linked list into 2 smaller linked lists and recursively use merge sort. 
Merge sort has a time complexity of O(nlogn).

7. Starting at the root, we can recursively check the height of each node see if it is greater than 1 or less than -1 and if so we know that it does not meet the requirements. This approach would be O(N) where N would be the amount of nodes.
*/