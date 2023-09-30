#include <iostream>
using namespace std;

class BankAccount {
    public:
        BankAccount(int dollars, int cents, double rate); //initializes account balance to $dollars.cents
        BankAccount(int dollars, double rate); //initializes account balance to $dollars.00
        BankAccount(); //initializes account balance to $0.00 and interest rate to 0.0%

        void set(int dollars, int cents, double rate);
        void set(int dollars, double rate);
        void update();

        double get_balance();

        double get_rate();

        void output(ostream& outs);

        private:
            double balance;
            double interest_rate;
            double fraction(double percent);
};       

int main() {
    BankAccount account1(120, 5.0), account2;
    cout<<"account1 initialized as follows:\n";
    account1.output(cout);
    cout<<"account2 initialized as follows:\n";
    account2.output(cout);

    account1 = BankAccount(999, 99, 5.5);
    cout<<"account 1 reset to the following:\n";
    account1.output(cout);
    return 0;
}
void BankAccount::output(ostream& outs) {
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}

BankAccount::BankAccount(int dollars, int cents, double rate) {
    if((dollars < 0) || (cents < 0) || (rate < 0)) {
        cout<<"Illegal values for money or interest rate.\n";
        exit(1);
    }
    balance = dollars + 0.01 * cents;
    interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate) {
    if((dollars < 0) || (rate < 0)) {
        cout<< "Illegal values for money or interest rate.\n";
        exit(1);
    }
    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount() : balance(0), interest_rate(0.0) {

}