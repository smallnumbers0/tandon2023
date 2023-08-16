#include <iostream>
using namespace std;

int factorial(int num);

int main() {

    int k_combs, nFact = 1, kFact = 1, n_kFact = 1, n, k;

    cout<<"Please enter an integer for n and k: "<<endl;
    cin>>n;
    cin>>k;

    nFact = factorial(n);
    kFact = factorial(k);
    n_kFact = factorial(n-k);

    k_combs = nFact / (kFact*n_kFact);

    cout<<k_combs<<endl;
}
int factorial(int num) {
    int factResult = 1;
    for(int i = 1; i <= num; i ++) {
        factResult *= i;
    }
    return factResult;
}

