#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

bool symbol_balanced(ifstream& input_file);
bool check_begin_end_pair(ifstream& input_file);


int main() {
    string file_name;
    cout << "Please enter the name of the file: " << endl;
    cin >> file_name;
    ifstream input_file(file_name);

    if (!input_file) {
        cout << "Error, file not found." << endl;
        exit(1);
    }

    if(!check_begin_end_pair(input_file)) {
        exit(1);
    }
    input_file.clear();                 
    input_file.seekg(0, ios::beg);

    
    if (symbol_balanced(input_file)) {
        cout << "The symbols are balanced." << endl;
    } else {
        cout << "The symbols are not balanced." << endl;
    }

    input_file.close();

    return 0;
}

bool symbol_balanced(ifstream& input_file) {
    stack <char> full_stack;
    string line;
    bool isEmpty = true;
    stack <char> symbols_stack;



    //Making a stack that contains all chars
    while (input_file >> line)
    {
        for (const char i : line)
        {

            full_stack.push(i);
        }
    }

    //Find all chars that are } ] ) and checks to see if the pair for it exists
    while(!full_stack.empty()) {
        char c = full_stack.top();

        switch (c) {
            case '}':
            case ']':
            case ')':
                symbols_stack.push(c);
                break;
            case '{':
                if(symbols_stack.top() == '}' && !symbols_stack.empty()) {
                    symbols_stack.pop();
                }
                else return false;
                break;

            case '[':
                if(symbols_stack.top() == ']' && !symbols_stack.empty()) {
                    symbols_stack.pop();
                }
                else return false;
                break;

            case '(':
               if(symbols_stack.top() == ')' && !symbols_stack.empty()) {
                    symbols_stack.pop();
                }
                else return false;
                break;

            default:
                break;
            }
            
            full_stack.pop(); //always remove each char
    }

    return isEmpty;
}

bool check_begin_end_pair(ifstream& input_file) {
    string check_begin;
    bool isPair = true;
    input_file>>check_begin;

    if(check_begin != "begin") {
        cout<<"The symbols are not balanced. Did not find begin/end pair"<<endl;
        isPair = false;
    }

    bool is_end = false;
    string check_end;
    while(input_file >> check_end) {
        if(check_end == "end") {
            is_end = true;
        }
    }
    if(!is_end) {
        cout<<"The symbols are not balanced. Did not find begin/end pair"<<endl;
        isPair = false;
    }
    return isPair;
}