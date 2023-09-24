# x = int(input("First input: "))
# y = int(input("Second input: "))

# if(x > 0 and y > 0):
#     print("Positive")
# elif((x > 0 and y < 0) or (x < 0 and y > 0)):
#     print("Balance")
# elif(x < 0 and y < 0):
#     print("Negative")

# Write either a for loop or a while loop which contains a print command inside of it in the following way:

# The loop starts with a loop variable that is equal to zero.  The loop ends when the loop variable is equal to 100. 
# The print command inside the loop prints the loop variable only if the loop variable is between the numbers 0 and 50 inclusive or the variable is between the numbers 62 and 100 inclusive


# for i in range(0, 101):
#     if(i >= 0 and i <= 50):
#         print(i)
#     elif(i >= 62 and i <= 100):
#         print(i)

# x = int(input("First input: "))   #converts 2 inputs into integers
# y = int(input("Second input: "))

# c = x + y #sum of inputs into c
# d = 5 

# if c > d:       #if c is greater than d prints "Happy"
#     print("Happy")
# elif c == d: #if value of c is equal to value of d prints "Glad"
#     print("Glad")
# elif c + d == 10:  #if sum of the value of c and d is equal to 10 prints "Wow"
#     print("Wow")
# else:
#     for i in range(0,51):  #if c is less than d prints c 50 times
#         print(c)

n = 1

while (n < 128):     

     n = n + n     

     print(n," ", end="")

print(" ")