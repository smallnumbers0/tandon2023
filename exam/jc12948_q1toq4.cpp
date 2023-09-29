//Jacky Choi
//jc12948

/*
1. Base Case: n = 0 => 3^0 = (3^1 -1)/2
                        1  = 1
IH: 
Assume: 3^k = (3^(k+1)-1)/2
Show: 3^(k+1) = (3^(k+2) -1)/2

Left Side:
1+3+9+27+...+3^k + 3^(k+1)
= 3^k + 3^(k+1) 
By IH: (3^(k+1) - 1)/2 + 3^(k+1)
= (3^(k+1)-1 + 2(3^k+1))/2
= (3^(k+1)-1 + 3^(k+1) + 3^(k+1))/2
= 3^(k+1) * 3^1 -1)/2
=> LHS = RHS  => (3^(k+2) - 1) /2 = (3^(k+2) -1)/2 
therefore 1+3+9+27+...+3^n = (3^(n+1))/2

2a. 
We can take the possibilties of all people in the picture and subtract from the possibility of both Hal and Ida in the picture:
Total combinations of 5  - combinations of Hal and Ida 
C(9,5) - (C(9,2) + C(7,3))

2b.
2 of the 5 elements must be in the subset. So we must remove all subsets without both 3 and 4.
for each subset we must chose 4 and 3 and then 8 choices left for the other 3 numbers.
C(10, 1) * C(9,1) * C(8,3)

3a.
Since 1 freshmen is out of sample, the total freshmen are 10 - 1. and Total students is 30 - 1;
There are 9 freshmen out of 29 total students
so 9 / 29

3b.
binary string of length 8
We add all possibilities of strings with more 0s and 1s and divide by the total possibilties
(C(8,5) + C(8,6) + C(8,7) + C(8,8)) / 2^8

4. function1:
    The outer loop is incrmeenting by a multiple of 5: log_5(n)
    the inner loop is just linear so n;
    so this is n*(log_5(n))

    The second group of loops has a constant of the if condition
    the outer loop for this is running at n
    the inner loop is the same
    so this is n^2

    so T(n) = theta(n * log(n))


    function2:
    the outer loop is again a multiple of 5: log_5(n)
    the inner loop depends on the outter loop and is also log_5(n). 
    1 + 5 + 25 + 125.. 5k-1

    so T(n) = theta(log(n)^2)
*/

