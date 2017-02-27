This work is produced by mliu2 and ywang20.
=============================================================
How to test it:
-Run "make all" in the command line to compile it.
-Run "./PA5 mliu2-ywang20-compareT.txt mliu2-ywang20-ArithmeticT.txt "

-For testing the EXTRA POINTS:
 -run”./PA5 mliu2-ywang20-EXTRA-VariableT.txt”
==============================================================
Test Cases: 

File name: mliu2-ywang20-ArithmeticT.txt
3/2 3/4 + 	:9/4 (double 2.25)
4/5 5/6 - 	:-1/30 (double -0.0333333)
7/12 1/8 * 	:7/96 (double 0.0729167)
5/8 1/94 / 	:235/4 (double 58.75)
4/4 3/3 + 	:2 (double 2)
3/9 5/10 - 	:-1/6 (double -0.166667)
13/52 12/18 * 	:1/6 (double 0.166667)
9/9 10/10 / 	:1 (double 1)
1 2 + 	:3 (double 3)
3 4 - 	:-1 (double -1)
5 6 * 	:30 (double 30)
7 8 / 	:7/8 (double 0.875)
3/-2 -3/4 + 	:-9/4 (double -2.25)
4/-5 5/-6 - 	:1/30 (double 0.0333333)
-7/12 -1/8 * 	:7/96 (double 0.0729167)
5/-8 1/-94 / 	:235/4 (double 58.75)
22/3 2/3 + 4 - 	:4 (double 4)
-1/3 -17/28 + 2/3 * 	:-79/126 (double -0.626984)
2/3 -1/3 -17/28 + * 	:-79/126 (double -0.626984)
2/3 4/3 - 5/2 + 	:11/6 (double 1.83333)
5/2 2/3 4/3 - + 	:11/6 (double 1.83333)



File name: mliu2-ywang20-compareT.txt
5/7 9/2 > 	:False
-1/2 -7/3 > 	:True
1/3 -3/2 > 	:True
88/22 33/11 > 	:True
5 6 > 	:False
17/25 7/13 < 	:False
3 -2/5 < 	:False
-2 -3/5 < 	:True
88/33 33/11 < 	:True
2/3 2/5 <=	:False
-34/7 -13/8 <=	:True
-1/17 7/44 <=	:True
6/4 3/2 <=	:True
-34/7 -13/8 >=	:False
-1/17 7/44 >=	:False
6/4 3/2 >=	:True
5 7 !=	:True
0 -3/2 !=	:True
-3/-2 3/2 !=	:False
9/10 8/7 !=	:True
99/33 33/11 !=	:False
27/59 -785/94 ==	:False
-27/59 -785/94 ==	:False
23 17/9 ==	:False
99/33 33/11 ==	:True
23/5 3/4 + 63/5 > 	:False
3/7 -1/2 * 1/2 < 	:True
20/4 2/7 - 5 < 	:True
40/4 5/7 / 10 < 	:False
63/5 23/5 3/4 + < 	:False
1/2 3/7 -1/2 * > 	:True
5 20/4 2/7 - > 	:True
10 40/4 5/7 / > 	:False

==============================================================


File name: mliu2-ywang20-EXTRA-VariableT.txt
x 2 = 	:2 (double 2)
x 2/4 = 	:1/2 (double 0.5)
x 3 + 	:7/2 (double 3.5)
1/2 x + 	:1 (double 1)
1/2 x - 	:0 (double 0)
x 1/5 - 	:3/10 (double 0.3)
x 0 * 	:0 (double 0)
9/8 x * 	:9/16 (double 0.5625)
x 5 / 	:1/10 (double 0.1)
6 x / 	:12 (double 12)
1/2 x + 	:1 (double 1)
1/2 x - 	:0 (double 0)
x 1/5 - 	:3/10 (double 0.3)
x 1/2 += 	:1 (double 1)
x 1/2 -= 	:1/2 (double 0.5)
x 1/2 *= 	:1/4 (double 0.25)
x 1/2 /= 	:1/2 (double 0.5)
y 3/2 = 	:3/2 (double 1.5)
x y = 	:3/2 (double 1.5)
y x = 	:3/2 (double 1.5)
x 3/2 ==	:True
x 1/2 !=	:True
x 0 > 	:True
x 2 >=	:False
x 1 < 	:False
x 0 <=	:False
x 1/2 += 1/2 += 	:5/2 (double 2.5)
x 2/3 *= 3/2 *= 	:5/2 (double 2.5)
x 2/3 -= 2/2 -= 	:5/6 (double 0.833333)
x 3/3 /= 1/2 /= 	:5/3 (double 1.66667)

==============================================================
PA5.cpp:

The int main(int argc, char* argv[]) :

The main function takes two parameter---- the count for strings in the command line and array of string argv. Inside the function, it first checks whether the input line has less than 2 strings. If yes, it will return an error and gets out of the function. If no, the function will keep going. A for loop comes up which will parse the input file and start doing the calculation. For here, we assume the expression should be correct, so we would not check most of errors. Inside the for loop, there is an while loop which end when reach the end of the input file. In side the while loop, we peek a char out of the input file and check its value with a while loop. While the char c is '\n' or reaches the end of file, the loop will end. 
Inside the loop, if it detect a whitespace it will skip this space and keep looking for others. 
If the next char is a number, it uses the overloaded >> to read the rational number value. If the next char is '-' and next next char is a number, it is also going to put the '-' back into the input file and read it as a rational number.The rational number will be added to the stack. If the next char is a alphabatic character, it is going to check in the variable list we created before, whether this variable exists already by findExp. If yes, it is going to get the variable out of the list and add it into the stack.  If it does not already exits, the program is going to check if there is an '=' sign as the operator. If the '=' was found, it is going to create a rational with its variable name to the list and also to the stack. Otherwise, an error called "Uninitialized expression " will be returned and exit. 
Inside this loop, it also checks for the operator. If any operator is detected, the top 2 rational on the stack will be pop out. If a compare operator is detected, it going to call the function compareTo, which will print out the result(Because we assume the compare operator will always be at the end.). If any other operator is detected, the program will either call calculateSelf or calculate to do the calculation. It depends on whether the operand would be changed. After doing calculating operators, its result will be push to the stack for later calculation. At the end of while loop, we peek a character to push the parsing process. Outside of this loop,  the program is going to check if the stack is empty, if no it is going to print it as the result. And it deletes the variable list and close the file at the end. 

int fineExp(Rational exps[50],char name):

The function findExp takes two parameter, a rational array of length 50(We assume ther is less than 50 variables) and the name of the variable as a char. Inside the function, it loops through all members of the rational array, if there is one match, returns its index. If no, return -1;

void compareTo(char f, char n, Rational& l, Rational& r):

The function compareTo takes four parameters, two chars for checking the operators and two reference to Rational l and r for doing the operation. Inside the function, it checks f and n both to do the specific comparison between l and r. Prints true if the comparison is true and vice versa.


void calculateSelf(char f,Rational& l,Rational& r):

The function calculateSelf takes 3 parameters a char and two reference of rational l and r. Inside the function, it does calculation based on the char f and make change to l (The left side of the operation), which would change the the value at that address.

Rational calculate(char f, Rational& l,Rational& r):

The function calculate takes three parameter, char f for checking the operation and two reference to Rational. Inside the function, it creates a new rational re and assign the result of arithmetic calculation to re. The type of arithmetic operation is decided by f. The function will return re to pass the result out.

===============================================================
===============================================================
class Rational:

-private members-
    int upper: Numerator of the Rational.
    int lower: Denominator of the Rational.
    char name: If the Rational is just a value, name is ‘’. If the Rational is a variable might be used later, store its name.
    void simplify(): Normalize this Rational by get the gcd of numerator and denominator and divide them by the gcd. Also check if the denominator is negative. If the denominator is negative, make the numerator negative and denominator positive.

————————————————————————————————————————
-public members-
    Rational(const Rational& r): Copy constructor, use initializer list to copy the numerator, denominator and name of Rational& r.
    Rational(const int wholeNumber): Constructor with only one argument, the numerator is initialized as whole number and the denominator is initialized as 1. Name is initialized as null.
    Rational(const int num, const int denom): Constructor with both numerator and denominator as arguments. Initialize the numerator as num and denominator as denom. If the  const int denom equals 0, the program will print error in the command line and exit automatically. Name is initialized as null.
    Rational(char n, const Rational& r): Constructor designed to initialize a variable. The char n is the name of the variable and copy the numerator and denominator of given const Rational& r to the variable.

    Rational(): Default constructor, initialize the numerator as 0 and denominator as 1.Name is initialized as null.
    ~Rational(): Destructor, set the numerator, denominator and name to 0.
    
    Rational& operator=(Rational b): Overload the assignment. Set the numerator and denominator same as the given Rational b. If the current name is not null, do not modify the name.
    char getName() const: Return name.
    double getDouble(): Convert the Rational into a double value and return it.


————————————————————————————————————————
-friend functions& operator overloading:
    friend Rational operator+(Rational& a, Rational& b): Make a Rational whose numerator is a.upper*b.lower+ a.lower*b.upper, and denominator is a.lower*b.lower. Simplify this Rational and return it.
    friend Rational operator-(Rational& a, Rational& b): Make a Rational whose numerator is a.upper*b.lower- a.lower*b.upper, and denominator is a.lower*b.lower. Simplify this Rational and return it.
    friend Rational operator*(Rational& a, Rational& b): Make a Rational whose numerator is a.upper*b.upper, and denominator is a.lower*b.lower. Simplify this Rational and return it.
    friend Rational operator/(Rational& a, Rational& b): Make a Rational whose numerator is a.upper*b.lower, and denominator is a.lower*b.upper. Simplify this Rational and return it.
    friend bool operator==(Rational& a, Rational& b): Return the boolean value of a.upper*b.lower == a.lower*b.upper.
    friend bool operator!=(Rational& a, Rational& b): Return the boolean value of a.upper*b.lower != a.lower*b.upper.
    friend bool operator>(Rational& a, Rational& b): Simplify a and b first(avoid having the denominator be negative), and return the boolean value of a.upper*b.lower > a.lower*b.upper.
    friend bool operator>=(Rational& a, Rational& b): Simplify a and b first(avoid having the denominator be negative), and return the boolean value of a.upper*b.lower >= a.lower*b.upper.
    friend bool operator<(Rational& a, Rational& b): Simplify a and b first(avoid having the denominator be negative), and return the boolean value of a.upper*b.lower < a.lower*b.upper.
    friend bool operator<=(Rational& a, Rational& b): Simplify a and b first(avoid having the denominator be negative), and return the boolean value of a.upper*b.lower <= a.lower*b.upper.
    friend Rational& operator+=(Rational& a, Rational& b): Set the numerator of a as a.upper*b.lower+ a.lower*b.upper, and the denominator of a as a.lower*b.lower. Simplify a and return a.
    friend Rational& operator-=(Rational& a, Rational& b): Set the numerator of a as a.upper*b.lower- a.lower*b.upper, and the denominator of a as a.lower*b.lower. Simplify a and return a.
    friend Rational& operator*=(Rational& a, Rational& b): Set the numerator of a as a.upper*b.upper, and the denominator of a as a.lower*b.lower. Simplify a and return a.
    friend Rational& operator/=(Rational& a, Rational& b): Set the numerator of a as a.upper*b.lower, and the denominator of a as a.lower*b.upper. Simplify a and return a.
    
    friend ostream& operator<<(ostream& a, Rational& b): If the denominator of Rational& b is 1, print the numerator only. Otherwise print the numerator, “/”, and denominator.
    friend istream& operator>>(istream& a, Rational& b): Get the numerator from istream& a first, if failed, return a and exit. If succeed, get the next character of istream& a. If the next character is an empty space, there is no denominator give, set the denominator of b to 1. If the next character is “/”, get the integer comes after “/” and set it as the denominator of Rational&b, return b then. 
    
    friend int gcd(int a, int b): Use recursion to find the gcd of int a and int b. If b equals 0 , then a is the gcd of the very beginning arguments.