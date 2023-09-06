#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0; i < 100; i++) {
        v.push_back(i);
    }
    v.push_back(900);
    v.insert(v.begin(), 200);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
}