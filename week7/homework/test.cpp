#include <iostream>
#include <cmath>

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 1;
    outSumDivs = 1; 

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            outCountDivs++;

            if (i != num / i) {
                outCountDivs++;
                outSumDivs += i + num / i;
            } else {
                outSumDivs += i;
            }
        }
    }
}

int main() {
    int num = 12;
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);

    std::cout << "Number of proper divisors: " << countDivs << std::endl;
    std::cout << "Sum of proper divisors: " << sumDivs << std::endl;

    return 0;
}

