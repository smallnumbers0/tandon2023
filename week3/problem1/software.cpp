#include<iostream>
using namespace std;
int main() {
    cout << "Enter the number of packages purchased: \n";
    int packages = 0;
    cin >> packages;

    if (packages < 10) {
        cout << "No discout applied\n";
    }
    else if (packages >= 10 && packages <= 19) {
        cout << "You get a 10% discount! Your discounted purchase price is $" << (packages * 99) - (packages * 99) * 0.1 << endl;
    }
    else if (packages >= 20 && packages <= 49) {
        cout << "You get a 20% discount! Your discounted purchase price is $" << (packages * 99) - (packages * 99) * 0.2 << endl;
    }
    else if (packages >= 50 && packages <= 99) {
        cout << "You get a 30% discount! Your discounted purchase price is $" << (packages * 99) - (packages * 99) * 0.3 << endl;
    }
    else {
        cout << "You get a 40% discount! Your discounted purchase price is $" << (packages * 99) - (packages * 99) * 0.4 << endl;
    }

    return 0;
}