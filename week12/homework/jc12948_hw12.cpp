#include <iostream>
using namespace std;

class Money {
    public:
        friend Money operator +(const Money& amount1, const Money& amount2);
        friend Money operator -(const Money& amount1, const Money& amount2);
        friend Money operator -(const Money& amount);
        friend bool operator ==(const Money& amount1, const Money& amount2);
        friend bool operator <(const Money& amount1, const Money& amount2);

        Money(long dollars, int cents);
        Money(long dollars);
        Money(); 

        double get_value() const;

        friend istream& operator >>(istream& ins, Money& amount);

        friend ostream& operator <<(ostream& outs, const Money& amount);

    private:
        long all_cents;
};

class Check {
    public:
    int get_number();
    Money get_amount();
    bool get_cashed();
    void set_number(int num);
    void set_amount(const Money& amount);
    void set_cashed(bool cashed);
    Check(int num, long dollars, int cents, bool cashed);

    Check(int num, long dollars, bool cashed);

    Check();
    friend istream& operator>>(istream& input, Check& check) {
        input >> check.number >> check.amount >> check.is_cashed;
        return input;
    }

private:
    int number;
    Money amount;
    bool is_cashed;

};



int main() {
    int numChecks;
    cout<<"How many checks do you have?: "<<endl;
    cin>>numChecks;
    cout<<"For each check, please enter check number, check amount, 1 if cashed and 0 if not."<<endl;
    cout<<"Example: 89 $50.99 1 "<<endl;

    Check* checks = new Check[numChecks];

    for(int i = 0; i < numChecks; i++) {
        cin >> checks[i];
    }

    delete[] checks;
    return 0;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout<<"Illegal values for dollars and cents.\n";
        exit(1);
    }

    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {
    //Body intentionally left blank.
}

Money::Money() : all_cents(0) {
    //Body intentionally left blank.
}

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

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

int Check::get_number() {
    return number;
}
Money Check::get_amount() {
    return amount;
}
bool Check::get_cashed() {
    return is_cashed;
}
void Check::set_number(int num) {
    this->number = num;
}
void Check::set_amount(const Money& amount) {
    this->amount = amount;
}
void Check::set_cashed(bool cashed) {
    this->is_cashed = cashed;
}

Check::Check(int num, long dollars, int cents, bool cashed) : number(num), amount(dollars, cents), is_cashed(cashed) {};

Check::Check(int num, long dollars, bool cashed) : number(num), amount(dollars, 0), is_cashed(cashed) {};

Check::Check() : number(0), amount(0, 0), is_cashed(false) {};