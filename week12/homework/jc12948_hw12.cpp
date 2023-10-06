#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Check;

class Money {
    long all_cents;

public:
    friend Money operator -(const Money& amount);
    // friend Money operator *(const Money& amount1, const Money& amount2);
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend bool operator <(const Money& amount1, const Money& amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money(); 
    double get_value() const;
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);
    
};

class Check {
    int number;
    Money amount;
    bool is_cashed;

public:
    int get_number() const;
    Money get_amount() const;
    bool get_cashed() const;
    void set_number(int number);
    void set_amount(const Money& amount);
    void set_cashed(bool cashed);
    Check(int number, long dollars, int cents, bool cashed);
    Check(int number, long dollars, bool cashed);
    Check();
    friend istream& operator>>(istream& input, Check& check) { //Check boolean for 1 or 0 only
        int is_cashed;
        input >> check.number >> check.amount >> is_cashed;
        if(is_cashed == 1) {
            check.is_cashed = true;
        }
        else if(is_cashed == 0) {
            check.is_cashed = false;
        }
        else {
            cout<<"Error. Could not determine if check is to be cashed. Entered something other than 1 or 0."<<endl;
            exit(1);
        }
        return input;
    }
    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check);
    

};

int digit_to_int(char c);
Money get_amount_cashed_checks(const Check checks[], int num_checks);
Money get_amount_uncashed_checks(const Check checks[], int num_checks);
Money get_total_deposit(const Money deposits[], int num_deposits);


int main() {
    int num_checks;
    int num_deposits;
    cout<<"How many checks do you have?: "<<endl;
    cin>>num_checks;

    cout<<"For each check, please enter check number, check amount, 1 if cashed and 0 if not."<<endl;
    cout<<"Examples: 89 $50.99 1 or 56 $19.22 0"<<endl;

    Check* checks = new Check[num_checks];

    for(int i = 0; i < num_checks; i++) {
        cin >> checks[i];
    }
    cout<<"How many deposits do you have?: "<<endl;
    cin>>num_deposits;
    Money* deposits = new Money[num_deposits];
    cout<<"Please enter your deposits in the following format: ($00.00): "<<endl;
    for(int i = 0; i < num_deposits; i++) {
        cin >> deposits[i];
    }

    //total depsotis
    Money new_balance;
    Money new_bank_balance;
    Money total_deposit;
    //totcal checks cashed
    Money amount_cashed_checks;
    //total checks uncashed
    Money amount_uncashed_checks;
    //total balance
    Money previous_balance;
    Money balance_difference;
    cout<<"Please enter previous balance ($00.00): "<<endl;
    cin>>previous_balance;
    //Instructions feel unclear. Why are we asking user for a new balance and then calculating a new balance? I never balanced a checkbook before.
    // cout<<"Please enter new balance according to the user: "<<endl;
    // cin>>new_balance;
    amount_cashed_checks = get_amount_cashed_checks(checks, num_checks);
    amount_uncashed_checks = get_amount_uncashed_checks(checks, num_checks);
    total_deposit = get_total_deposit(deposits, num_deposits);
    new_balance = previous_balance - amount_cashed_checks + amount_uncashed_checks + total_deposit; //The new account balance should be the old balance plus all deposits,minus all checks that have been cashed.
    new_bank_balance = previous_balance - amount_cashed_checks + total_deposit;
    balance_difference = new_balance - new_bank_balance;
    //To keep the difference positive
    if(balance_difference < 0) {
        balance_difference = -balance_difference;
    }

    cout<<"The total amount from cashed checks is: "<<amount_cashed_checks<<endl;
    cout<<"The total amount from uncashed checks is: "<<amount_uncashed_checks<<endl;
    cout<<"The total amount from deposits is "<<total_deposit<<endl;
    cout<<endl;
    cout<<"Your new balance is: "<<new_balance<<endl;
    cout<<"The bank's new balance is: "<<new_bank_balance<<endl;
    cout<<"The difference between your balance and the bank is a total of "<<balance_difference<<endl;
    cout<<"List of cashed checks: "<<endl;
     for(int i = 0; i < num_checks; i++) {
        if(checks[i].get_cashed() == true) {
            cout << checks[i]<<endl;
        }
    }
    cout<<"List of uncashed checks: "<<endl;
    for(int i = 0; i < num_checks; i++) {
        if(checks[i].get_cashed() == false) {
            cout << checks[i]<<endl;
        }
    }

    delete[] deposits;
    delete[] checks;
    return 0;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}
bool operator ==(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}
bool operator <(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents < amount2.all_cents);
}
double Money::get_value() const {
    return all_cents * 0.01;
}
istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins>>one_char;

    if (one_char == '-') {
        negative = true;
        ins>>one_char; //read '$'
    }
    else {
        negative = false;
    }

    ins>>dollars>>decimal_point>>digit1>>digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout<<"Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (amount.all_cents < 0 ) {
        outs<<"-$"<<dollars<<'.';
    }
    else {
        outs<<"$"<<dollars<<'.';
    }
    if (cents < 10) {
        outs<<'0';
    }
    outs<<cents;
    return outs;
}


int Check::get_number() const {
    return number;
}
Money Check::get_amount() const {
    return amount;
}
bool Check::get_cashed() const {
    return is_cashed;
}
void Check::set_number(int number) {
    this->number = number;
}
void Check::set_amount(const Money& amount) {
    this->amount = amount;
}
void Check::set_cashed(bool cashed) {
    this->is_cashed = cashed;
}

Check::Check(int number, long dollars, int cents, bool cashed) : number(number), amount(dollars, cents), is_cashed(cashed) {};
Check::Check(int number, long dollars, bool cashed) : number(number), amount(dollars, 0), is_cashed(cashed) {};
Check::Check() : number(0), amount(0, 0), is_cashed(false) {};

Money::Money(long dollars) : all_cents(dollars * 100) {}
Money::Money() : all_cents(0) {}
Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }

    all_cents = dollars * 100 + cents;
}

Money get_amount_cashed_checks(const Check checks[], int num_checks) {
    Money amount;
    for(int i = 0; i < num_checks; i++) {
        if(checks[i].get_cashed() == true) {
            amount = amount + checks[i].get_amount();
        }
    }
    return amount;
}

Money get_amount_uncashed_checks(const Check checks[], int num_checks) {
    Money amount;
    for(int i = 0; i < num_checks; i++) {
        if(checks[i].get_cashed() == false) {
            amount = amount + checks[i].get_amount();
        }
    }
    return amount;
}

Money get_total_deposit(const Money deposits[], int num_deposits) {
    Money amount;
    for(int i = 0; i < num_deposits; i++) {
        amount = amount + deposits[i];
    }
    return amount;
}


ostream& operator<<(ostream& outs, const Check& check) {
    outs << "Check Number: " << check.get_number() << ", Amount: " << check.get_amount();
    return outs;
}