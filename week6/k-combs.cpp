#include <iostream>

using namespace std;

int main() {

    int k_combs, nFact = 1, kFact = 1, n_kFact = 1, n, k;

    cout<<"Please enter an integer for n and k: "<<endl;
    cin>>n;
    cin>>k;

    for(int i = 1; i <= k; i++) {
        kFact *= i;
    }
    for(int i = 1; i <= n; i++) {
        nFact *= i;
    }
    for(int i = 1; i <= n-k; i++) {
        n_kFact *= i;
    }

    k_combs = nFact / (kFact*n_kFact);

    cout<<k_combs<<endl;
}