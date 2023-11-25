bool compare(vector<int> bst, vector<int> list) {
    
}

void bstVector(BSTNode *root, vector<int> &v) { //norder traversal
    if(root != nullptr) {
        bstVector(root->left, v);
        v.pushback(root.val);
        bstVector(root->right, v);
    }
}