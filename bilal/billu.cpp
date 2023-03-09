#include<iostream>
#include<string>
#include <windows.h>
using namespace std;

////////////////////// ALL FUNCTION //////////////////////////

void Q1();
void sum(int a, int b);
void square(int a);
void length_of_string(string a);
void Q5(int j);
void odd_num(int k);
void factorial(int c);
void vowels(string z);
void factors(int x);
void swap(int& a, int& b);
/////////////////////////////////////////////////////////////////////
int main()
{
    system("Color 91");
    int choice;
    cout << endl << "Enter Question number";
    cin >> choice;
    system("CLS");
    string alphabet;
    switch (choice)
    {
    case 1:
        cout << " Print first ten numbers " << endl;
        Q1(); break;
    case 2:
        cout << " Sum of two numbers ";
        int num1, num2;
        cout << endl << "Enter number 1 :"; cin >> num1;
        cout << endl << "Enter number 2 :";  cin >> num2;
        sum(num1, num2);
        break;
    case 3:
        cout << "Find square of given number ";
        int input1;
        cout << endl << "Enter number that you want square of :";
        cin >> input1;
        square(input1);
        break;
    case 4:
        
        cout << " Find length of String " << endl;
        cout << "Write  any text here :";
        cin.ignore();
        getline(cin, alphabet);
        length_of_string(alphabet);
        break;
    case 5:
        cout << "Print numbers from 1 to given number " << endl;
        int input2;
        cout << "Enter the number :"; cin >> input2;
        Q5(input2);
        break;
    case 6:
        cout << "Print odd numbers from 1 to given number " << endl;
        int input6;
        do
        {
            cout << endl << "Enter the number :"; cin >> input6;
        } while (input6 < 0);
        odd_num(input6);
        break;
    case 7:
        cout << " Find Factorial of given number " << endl;
        int input7;
        do {
            cout << endl << "Enter the number :"; cin >> input7;
        } while (input7 < 0);
        factorial(input7);
        break;
    case 8:
        cout << "Find number of Vowels in string ";
        cout << endl << "Enter text here :"; 
        cin.ignore();
        getline(cin, alphabet);

        vowels(alphabet);
        break;
    case 9:
        int input9;
        cout << "Find Factors of given number ";
        cout << endl << "Enter The number :"; cin >> input9;
        factors(input9);
        break;
    case 10:
        cout << " Swap the Two numbers " << endl;
        int number1, number2;
        do
        {
            cout << "Enter  first value :";
            cin >> number1;
            cout << endl << "Enter second value  :";
            cin >> number2;
        } while (number1 < 0 && number2 < 0 || number1 < 0 || number2 < 0);
        swap(number1, number2);
        cout << "First value is :" << number1;
        cout << "\nSecond value is :" << number2;
        break;
    default:
        return main();
    }
}

/////////////// Q.1 //////////////
void Q1() {
    for (int i = 1; i <= 10; i++)
        cout << i << endl;
}
/////////////// Q.2 //////////////
void sum(int a, int b) {
    int sum = a + b;
    cout << endl << "The sum of " << a << " and " << b << " is " << sum;
}
/////////////// Q.3 //////////////
void square(int a) {
    int square = a * a;
    cout << "Square of " << a << " is " << square;
}
/////////////// Q.4 //////////////
void length_of_string(string a) {
    cout << endl << a.length();
}
/////////////// Q.5 //////////////
void Q5(int j)
{
    for (int i = 1; i <= j; i++)
        cout << i << endl;
}
/////////////// Q.6 //////////////
void odd_num(int k)
{
    for (int i = 1; i <= k; i++)
        if (i % 2 != 0)
            cout << i << endl;
}
/////////////// Q.7 //////////////
void factorial(int c)
{
    int factorial = 1;
    for (int i = 1; i <= c; i++)
    {
        factorial = factorial * i;
    }
    cout << "factorial of " << c << " is " << factorial;
}
////////////////////// Q. 8  ///////////////
void vowels(string z) {
    int length = z.length();
    int count=0; 
    for (int i = 0; i < length; i++) {
        if (z[i] == 'A' || z[i] == 'E' || z[i] == 'I' || z[i] == 'O' || z[i] == 'U' || z[i] == 'a' || z[i] == 'e' || z[i] == 'i' || z[i] == 'o' || z[i] == 'u')
            count++;
    }
    cout << endl << "The number of vowels in " << z << " is " << count;
}

void factors(int x) {              /////// Q.9 /////////////
    for (int i = 1; i <= x; i++)
        if (x % i == 0)
            cout << "\t" << i;
}

void swap(int& a, int& b)           ////////// Q.10 /////////////
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}