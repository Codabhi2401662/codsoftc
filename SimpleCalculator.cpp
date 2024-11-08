#include <iostream>
using namespace std;

int main() 
{
    double num1, num2;
    char operation;

    // User input for two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // User input for the operation
    cout << "Select operation (+, -, *, /): ";
    cin >> operation;

    // Perform the operation based on user choice
    switch (operation) {
        case '+':
            cout << "Result= " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result= " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result= " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result= " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation selected." << endl;
            break;
    }

    return 0;
}
