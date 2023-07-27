/*
Write a program that does the following:
• Ask user to input three Real numbers a, b and c. They represent the parameters of a
quadratic equation 𝑎𝑥! + 𝑏𝑥 + 𝑐 = 0
• Classify to one of the following:
- ’Infinite number of solutions’ (for example, 0𝑥! + 0𝑥 + 0 = 0 has infinite number of solutions)
- ’No solution’ (for example, 0𝑥! + 0𝑥 + 4 = 0 has no solution)
- ’No real solution’ (for example, 𝑥! + 4 = 0 has no real solutions)
- ’One real solution’
- ’Two real solutions’
• In cases there are 1 or 2 real solutions, also print the solutions.
Notes:
1. If 𝑎 ≠ 0 and there are real solutions to the equation, you can get these solutions using
the following formula:
The number of solutions depends on whether (b2 -4ac) is positive, zero, or negative.
2. In order to calculate the square root of a number (of type double), you should call the sqrt function, located in the cmath library.
Follow the syntax as demonstrated in the code below:
   #include <iostream>
   #include <cmath>
   using namespace std;
   int main() {
       double x = 2.0;
       double sqrtResult;
       sqrtResult = sqrt(x);
       cout<<sqrtResult<<endl;
       return 0;
}
Note that you first need to include the cmath library, and then you can call the sqrt function, passing the argument that you want to calculate the square root of, enclosed in parentheses.
Your program should interact with the user exactly as it shows in the following example: Please enter value of a: 1
Please enter value of b: 4
Please enter value of c: 4
This equation has a single real solution x=-2.0
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, c;
    double discriminant, resultOne, resultTwo;
    
    cout<<"Please enter a value for a: "<<endl;
    cin>>a;
    cout<<"Please enter a value for b: "<<endl;
    cin>>b;
    cout<<"Please enter a value for c: "<<endl;
    cin>>c;

    //Solving

    discriminant = pow(b, 2) - (4 * a * c);
    

    //Determining solutions

    if(a == 0 && b == 0 && c == 0) {
        cout<<"Infinite number of solutions"<<endl;
    }
    else if(a == 0 && b == 0 && c != 0) {
        cout<<"No solution"<<endl;
    }
     else if(a != 0 && discriminant < 0) {
        cout<<"No real solutions"<<endl;
    }
    else if(a != 0 && discriminant == 0) {
        resultOne = (-b + sqrt(discriminant)) / (2 * a);
        cout<<"One real solution: "<<resultOne<<endl;
    }
    else if(a != 0 && discriminant > 0) {
        resultOne = (-b + sqrt(discriminant)) / (2 * a);
        resultTwo = (-b - sqrt(discriminant)) / (2 * a);
        cout<<"Two real solutions: "<<resultOne<<" and "<<resultTwo<<endl;
        cout<<resultOne<<endl;
    }
    else 
        cout<<"No Real Solutions"<<endl;

   
    return 0;
}