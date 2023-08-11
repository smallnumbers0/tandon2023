#include <iostream> 
using namespace std; 

int main(){

    int input;
    cout<<"Enter an integer: "<<endl;
    cin>>input;

    for(int i = 1; i <= input; i++){ //for loop for the height/columns square
        for(int j = 1; j <= input; j++){ //for loop for the width/rows of a square
            if(i == 1 || i == input || j == 1 || j == input){ //hollow square
                cout << "#";
            }
            else if(i == j || (i+j == input+1)){ //diagonals
                cout << "$"; 
            }
            else{
                cout << " ";
            }

        }


        cout << '\n'; 
    }

    return 0; 
}